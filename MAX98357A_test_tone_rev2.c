#include <stdio.h>
#include <math.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2s_std.h"
#include "esp_log.h"

#define PIN_BCLK   4
#define PIN_LRCLK  6
#define PIN_DIN    5

#define SAMPLE_RATE     48000
#define TONE_HZ         1000
#define BITS_PER_SAMPLE I2S_DATA_BIT_WIDTH_16BIT
#define TABLE_LEN       256
#define AMPLITUDE       32000

static const char *TAG = "I2S_MONO_TEST";
static int16_t sine_table[TABLE_LEN];

static void fill_sine_table(void)
{
    for (int i = 0; i < TABLE_LEN; i++) {
        float theta = 2.0f * (float)M_PI * (float)i / (float)TABLE_LEN;
        sine_table[i] = (int16_t)(AMPLITUDE * sinf(theta));
    }
}

void app_main(void)
{
    fill_sine_table();
    ESP_LOGI(TAG, "Starting mono I2S tone at %d Hz", TONE_HZ);

    // --- Create I2S channel ---
    i2s_chan_handle_t tx_chan;
    i2s_chan_config_t chan_cfg = I2S_CHANNEL_DEFAULT_CONFIG(I2S_NUM_0, I2S_ROLE_MASTER);
    chan_cfg.dma_desc_num = 6;
    chan_cfg.dma_frame_num = 240;
    ESP_ERROR_CHECK(i2s_new_channel(&chan_cfg, &tx_chan, NULL));

    // --- Configure standard I2S in Philips format ---
    i2s_std_config_t std_cfg = {
        .clk_cfg  = I2S_STD_CLK_DEFAULT_CONFIG(SAMPLE_RATE),
        .slot_cfg = I2S_STD_PHILIPS_SLOT_DEFAULT_CONFIG(BITS_PER_SAMPLE, I2S_SLOT_MODE_MONO),
        .gpio_cfg = {
            .mclk = I2S_GPIO_UNUSED,
            .bclk = PIN_BCLK,
            .ws   = PIN_LRCLK,
            .dout = PIN_DIN,
            .din  = I2S_GPIO_UNUSED,
        },
    };

    // Force data into LEFT slot (use RIGHT if your amp is set that way)
    std_cfg.slot_cfg.slot_mask = I2S_STD_SLOT_RIGHT
    ;

    ESP_ERROR_CHECK(i2s_channel_init_std_mode(tx_chan, &std_cfg));
    ESP_ERROR_CHECK(i2s_channel_enable(tx_chan));

    // --- Generate and send tone ---
    const int frames = 512;
    int16_t *buffer = heap_caps_malloc(frames * sizeof(int16_t), MALLOC_CAP_DEFAULT);
    float idx = 0.0f;
    float step = (float)TABLE_LEN * ((float)TONE_HZ / (float)SAMPLE_RATE);

    while (true) {
        for (int n = 0; n < frames; n++) {
            buffer[n] = sine_table[(int)idx];
            idx += step;
            if (idx >= TABLE_LEN) idx -= TABLE_LEN;
        }

        size_t bytes_written = 0;
        i2s_channel_write(tx_chan, buffer,
                          frames * sizeof(int16_t),
                          &bytes_written,
                          portMAX_DELAY);
    }
}

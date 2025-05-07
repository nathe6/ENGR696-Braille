/*
 * tables.h
 *
 *  Created on: May 6, 2025
 *      Author: Nathaniel Setiawan
 */

#ifndef MAIN_TABLES_H_
#define MAIN_TABLES_H_

#include <stdio.h>

int alphabetList [] = {{1, 0, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0}, {1, 1, 0, 0, 0, 0},
                       {1, 0, 0, 1, 1, 0}, {1, 0, 0, 0, 1, 0}, {1, 1, 0, 0, 1, 0},
                       {1, 1, 0, 1, 1, 0}, {1, 1, 0, 1, 0, 0}, {0, 1, 0, 1, 0, 0},
                       {0, 1, 0, 1, 1, 0}, {1, 0, 1, 0, 0, 0}, {1, 1, 1, 0, 0, 0},
                       {1, 0, 1, 1, 0, 0}, {1, 0, 1, 1, 1, 0}, {1, 0, 1, 0, 1, 0},
                       {1, 1, 1, 1, 0, 0}, {1, 1, 1, 1, 1, 0}, {1, 1, 1, 0, 1, 0},
                       {0, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 1, 0}, {1, 0, 1, 0, 0, 1},
                       {1, 1, 1, 0, 0, 1}, {0, 1, 0, 1, 1, 1}, {1, 0, 1, 1, 0, 1},
                       {1, 0, 1, 1, 1, 1}, {1, 0, 1, 0, 1, 1}};

void alphabetCall(int select);
void numberCall(int select);
void wordCall(int select);
                    
#endif
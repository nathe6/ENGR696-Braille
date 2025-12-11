/*
 * tables.h
 *
 *  Created on: May 6, 2025
 *      Author: Nathaniel Setiawan
 */

#ifndef MAIN_TABLES_H_
#define MAIN_TABLES_H_
#include <string.h>
#include <stdio.h>

char alphabetList [][6] = {{1, 0, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0}, {1, 1, 0, 0, 0, 0},
                       {1, 0, 0, 1, 1, 0}, {1, 0, 0, 0, 1, 0}, {1, 1, 0, 0, 1, 0},
                       {1, 1, 0, 1, 1, 0}, {1, 1, 0, 1, 0, 0}, {0, 1, 0, 1, 0, 0},
                       {0, 1, 0, 1, 1, 0}, {1, 0, 1, 0, 0, 0}, {1, 1, 1, 0, 0, 0},
                       {1, 0, 1, 1, 0, 0}, {1, 0, 1, 1, 1, 0}, {1, 0, 1, 0, 1, 0},
                       {1, 1, 1, 1, 0, 0}, {1, 1, 1, 1, 1, 0}, {1, 1, 1, 0, 1, 0},
                       {0, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 1, 0}, {1, 0, 1, 0, 0, 1},
                       {1, 1, 1, 0, 0, 1}, {0, 1, 0, 1, 1, 1}, {1, 0, 1, 1, 0, 1},
                       {1, 0, 1, 1, 1, 1}, {1, 0, 1, 0, 1, 1}};

char numberList [][6] = {{0, 1, 1, 1, 0, 0}, {1, 0, 0, 0, 0, 0}, {1, 0, 1, 0, 0, 0},
					 {1, 1, 0, 0, 0, 0}, {1, 1, 0, 1, 0, 0}, {1, 0, 0, 1, 0, 0},
					 {1, 1, 1, 0, 0, 0}, {1, 1, 1, 1, 0, 0}, {1, 0, 1, 1, 0, 0},
					 {0, 1, 1, 0, 0, 0}};
					 
char wordList [] = {}; // TBA
/* 
List: Good, Tree, Cool, From, Stay, Come, Hope, Need, Game, Also, Able, Cook, Calm, Move, Push, Pull, More, Near,
Open, Love, Chose, Blind
*/

void alphabetCall(int select);
void numberCall(int select);
void wordCall(int select);
                    
#endif
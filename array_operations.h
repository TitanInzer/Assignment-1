// array_operations.h
#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H

#include <fstream>

const int ROWS = 10;
const int COLS = 10;

void readData(int arr[][COLS], std::ifstream& inFile);                         /* Creates the Read Data Function */
int checkNumber(int arr[][COLS], int number);                                  /* Creates the checkNumber Function */
void modifyValue(int arr[][COLS], int index, int newValue, int& oldValue);     /* Creates the modifyValue Function */
void addValue(int arr[][COLS], int number);                                    /* Creates the addValue Function */
void removeValue(int arr[][COLS], int index);                                  /* Creates the removeValue Function */

#endif
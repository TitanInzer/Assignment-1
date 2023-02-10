#include "array_operations.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <exception>

/* Implementation Functions*/

void readData(int arr[][COLS], std::ifstream& inFile) {   /* Reads the File then Iterates through it and creates an array */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            inFile >> arr[i][j];
        }
    }
}

int checkNumber(int arr[][COLS], int number) {        /* Iterates through the array to find if a value exists in the array */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] == number) {
                return i * COLS + j;                 /* Returns the Index at which it is Found */
            }
        }
    }
    return -1;
}

void modifyValue(int arr[][COLS], int index, int newValue, int& oldValue) {   /* Finds Value at given index then replaces it with the new given value */
    oldValue = arr[index / COLS][index % COLS];
    arr[index / COLS][index % COLS] = newValue;
}

void addValue(int arr[][COLS], int number) {     /* Adds a new value at the end of the array*/
    arr[ROWS - 1][COLS - 1] = number;
}

void removeValue(int arr[][COLS], int index) {   /* Removes the Value at the Given Index */
    arr[index / COLS][index % COLS] = 0;
}

/* Test Case */

int main() {
    int arr[ROWS][COLS];
    std::ifstream inFile("ArrayNumbers.txt");                  /* Opens the file of the given name and checks if it can be opened */
    if (!inFile) {
        std::cerr << "Could not open file!" << std::endl;
        exit(1);
    }

    readData(arr, inFile);                /* Runs the readData function and applies it to the given file */
    inFile.close();

    int number;                          /* Asks User for a Number then Applies it to the checkNumber Function */
    std::cout << "Enter a Number: ";
    std::cin >> number;
    int index = checkNumber(arr, number);
    if (index != -1) {
        std::cout << "Number " << number << " found at index " << index << std::endl;   /* Case if the Number is in the Array */
    }
    else {
        std::cout << "Number " << number << " not found." << std::endl;         /* Case if the Number is not in the Array */
    }

    int index1;   /* Asks the User for an Index Value */
    try {
        std::cout << "Enter the Index you Wish to Change: ";
        std::cin >> index1;
        if (!std::cin) {    /* Will Throw an error if an int is not entered */
            throw std::invalid_argument("Invalid Input for Index");
        }
        int newValue;     /* Asks the User for a New Value */
        std::cout << "Enter a New Value: ";
        std::cin >> newValue;
        if (!std::cin) {       /* Will Throw an error if an int is not entered */
            throw std::invalid_argument("Invalid Input for New Value");
        }
        int oldValue;
        modifyValue(arr, index1, newValue, oldValue);   /* Runs the modifyValue function */
        std::cout << "Value at index " << index1 << " changed from " << oldValue << " to " << newValue << std::endl;
    }
    catch (std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl; /* Throws Error */
        std::cin.clear();  /* Clears the Error */
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  /* Allows for the next Function to be ran */
    }

    int newNumber;
    try {
        std::cout << "Enter the Value you would like to Add: ";  /* Asks the User to enter a New Number */
        std::cin >> newNumber;
        if (!std::cin) {        /* Will Throw an error if an int is not entered */
            throw std::invalid_argument("Invalid Input");
        }
        addValue(arr, newNumber);   /* Runs the addValue function */
        std::cout << "Number " << newNumber << " added at the end of the array." << std::endl;
    } catch (std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;   /* Throws Error */
        std::cin.clear();   /* Clears the Error */
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   /* Allows for the next Function to be ran */
    }

    int index2;
    std::cout << "Enter the Index you would like to Remove: ";  /* Asks the User for an index to be removed */
    std::cin >> index2;
    removeValue(arr, index2);   /* Runs the removeValue Function */
    std::cout << "Value at index " << index2 << " removed." << std::endl;

    return 0;
}
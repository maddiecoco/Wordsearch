#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector> 

using namespace std;

// Part A: Card class
class Grid {

public:
    
    void readFile(string fileName);
    void resize(int newRows, int newCols);

private:
    Matrix matrix;
    int rows;
    int cols;
};

struct Matrix {
    int rows;
    int cols;
    int** data;  // Pointer to a 2D array

    // Constructor
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        // Allocate memory for the matrix
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }

        // Initialize matrix elements to zero (or any other default value)
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0;  // You can change this to set a different default value
            }
        }
    }

    // Destructor
    ~Matrix() {
        // Deallocate memory when the object is destroyed
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Matrix element accessors and mutators
    int getElement(int row, int col) const {
        return data[row][col];
    }

    void setElement(int row, int col, int value) {
        data[row][col] = value;
    }
};


#endif
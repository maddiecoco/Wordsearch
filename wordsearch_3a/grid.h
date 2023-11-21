#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector> 
#include <fstream>

using namespace std;


class Grid {

public:
    // Constructor that reads the grid from a file
    Grid(const string& filename);

    // Function to print the grid
    void printGrid() const;
    vector<vector<char>> getMatrix();
    int getRows();
    int getCols();

private:
    int rows;
    int cols;
    vector<vector<char>> matrix;
};


#endif
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

private:
    int rows;
    int cols;
    std::vector<std::vector<char>> matrix;
};


#endif
#include "grid.h"
#include <fstream>

void Grid::readFile(string fileName)
{
    // Read file and add letters to a matrix
    string temp;
    ifstream infile;
    infile.open(fileName); // Put path of file in quotes

    if(!infile)
    {
        cerr << "Couldn't open file, check path" << endl;
    }

    infile >> rows >> cols;
    char curr;

    Matrix newMatrix(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            infile >> curr;
            newMatrix.setElement(i, j, curr);
        }
    }    

    matrix = newMatrix;
}

void resize(int newRows, int newCols) {
        // Create a new matrix with the desired size
        Matrix newMatrix(newRows, newCols);
}
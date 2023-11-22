// Includes necessary libraries and headers
#include <iostream>
#include <string>
#include <ctime>
#include <list>
#include <cstdlib>
#include "dictionary.h"
#include "grid.h"

// Function to find matching words in a grid given a dictionary
void findMatches(Dictionary& dict, Grid& grid)
{
    // Set the maximum and minimum lengths for words to search for
    int maxLength = 15, minLength = 4;
    int l, row, col;
    string word;
    vector<vector<char>> matrix = grid.getMatrix(); // Retrieve the grid's matrix

    // Iterate through each cell of the grid
    for (int r = 0; r < grid.getRows(); r++) {
        for (int c = 0; c < grid.getCols(); c++) {

            // The following blocks of code search for words in different directions
            // starting from the current cell (r, c)

            // Search horizontally to the left
            row = r, col = c;
            word = "";
            for (l = 0; l <= maxLength; l++) {
                word += matrix[row][col];
                if (word.length() >= minLength) {
                    if (dict.lookupWord(word)) {
                        cout << word << endl;
                    }
                }
                // Wrap around if the edge of the grid is reached
                if (col == 0) {
                    col = grid.getCols() - 1;
                } else {
                    col--;
                }
            }

            // Additional blocks of code likely follow similar patterns,
            // searching in different directions (e.g., diagonally, vertically)
            // and wrapping around the edges of the grid.

            // ...
            // Rest of the code for other search directions
            // ...
        }
    }
}

// The main function
int main() {
    Dictionary dict;

    // Read words into the dictionary from a file
    dict.readFile();
    // Sort the words in the dictionary
    dict.selectionSort();
    // Print the sorted words
    dict.printVector();

    // Create a grid from an input file
    Grid grid("input30");

    // Find matches between the dictionary and the grid
    findMatches(dict, grid);

    return 0;
}

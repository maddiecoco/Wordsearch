// Created by nehae on 10/18/2023.
// The Main file demonstrates creating a deck, printing it, shuffling it, and then printing the shuffled deck.


#include <iostream>
#include <string>
#include <ctime>
#include <list>
#include <cstdlib>
#include "dictionary.h"
#include "grid.h"


void findMatches(Dictionary& dict, Grid& grid)
{
    // Max and min lengths of words
    int maxLength = 15, minLength = 4; 
    int l, row, col;
    string word;
    vector<vector<char>> matrix = grid.getMatrix();

    //Iterate through each element in the grid
    for (int r = 0; r < grid.getRows(); r++) {
        for (int c = 0; c < grid.getCols(); c++) {

            // Search directly up
            // Set row and col to current row and col
            row = r, col = c;
            //Initialize word to be empty
            word = ""; 
            //Add up to the maxLength of characters
            for (l = 0; l <= maxLength; l++) {
                word += matrix[row][col];   
                if (word.length() >= minLength) { 
                    //Look up the word and if it exists, print it out
                    if (dict.lookupWord(word)) {
                        cout << word << endl;
                    }
                }
                //Iterate until at the edge, then wrap
                if (col == 0) {
                    col = grid.getCols() - 1;
                } else {
                    col--;
                }
            } 
            //End searching up

            //Search up and right (diagonal)
            row = r, col = c;
            //Initialize word to be empty
            word = "";
            for (l = 0; l <= maxLength; l++) {
                //Add on the current character
                word += matrix[row] [col];
                //Look up the word and if it exists, print it out
                if (word.length() >= minLength) {
                    if (dict.lookupWord(word)) {
                        cout << word << endl;
                    }
                }
                //Iterate until at the edge, then wrap
                if (col == 0) {
                    col = grid.getCols() - 1;
                } else {
                    col--;
                }
                if (row == grid.getRows() - 1) {
                    row = 0;
                } else {
                    row++;
                }
            }
            //End search up and right

            //Search to the right
            row = r, col = c; 
            //Initialize word to be empty
            word = ""; 
            for (l = 0; l <= maxLength; l++) {
                word += matrix[row][col];
                //Look up the word and if it exists, print it out
                if (word.length() >= minLength) {
                    if (dict.lookupWord(word)) {
                        cout << word << endl;
                    }
                }
                //Iterate until at the edge, then wrap
                if (row == grid.getRows() - 1) {
                    row = 0;
                } else {
                    row++;
                }
            } 
            //End search to the right

            //Search down and right (diagonal)
            row = r, col = c;
            word = "";
            for (l = 0; l <= maxLength; l++) {
                word += matrix[row][col];

                //Look up the word and if it exists, print it out
                if (word.length() >= minLength) {
                    if (dict.lookupWord(word)) {
                        cout << word << endl;
                    }
                }
                //Iterate until at the edge, then wrap
                if (col == grid.getCols() - 1) {
                    col = 0;
                } else {
                    col++;
                }
                if (row == grid.getRows() - 1) {
                    row = 0;
                } else {
                    row++;
                }
            } //End search down and right

            //Search directly down
            row = r, col = c;
            word = "";

            for (l = 0; l <= maxLength; l++) 
            {
                word += matrix[row][col];

                //Look up the word and if it exists, print it out
                if (word.length() >= minLength) {
                    if (dict.lookupWord(word)) {
                        cout << word << endl;
                    }
                }
                //Iterate until at the edge, then wrap
                if (col == grid.getCols() - 1) {
                    col = 0;
                } else {
                    col++;
                }
            } //End search down

            //Search down and left (diagonal)
            row = r, col = c; 
            word = "";
            for (l = 0; l <= maxLength; l++) {
                word += matrix[row][col];
                
                //Look up the word and if it exists, print it out
                if (word.length() >= minLength) {
                    if (dict.lookupWord(word)) {
                        cout << word << endl;
                    }
                }
                //Iterate until at the edge, then wrap
                if (col == grid.getCols() - 1) {
                    col = 0;
                } else {
                    col++;
                }
                if (row == 0) {
                    row = grid.getRows() - 1;
                } else {
                    row--;
                }
            } //End search down and left

            //Search to the left
            row = r, col = c; 
            word = "";

            for (l = 0; l <= maxLength; l++) {
                word += matrix[row][col];

                //Look up the word and if it exists, print it out
                if (word.length() >= minLength) {
                    if (dict.lookupWord(word)) {
                        cout << word << endl;
                    }
                }
                //Iterate until at the edge, then wrap
                if (row == 0) {
                    row = grid.getRows() - 1;
                } else {
                    row--;
                }
            } //End search left

            //Search up and left (diagonal)
            row = r, col = c;
            word = "";

            for (l = 0; l <= maxLength; l++) {
                word += matrix[row][col];

                //Look up the word and if it exists, print it out
                if (word.length() >= minLength) {
                    if (dict.lookupWord(word)) {
                        cout << word << endl;
                    }
                }
                //Iterate until at the edge, then wrap
                if (col == 0) {
                    col = grid.getCols() - 1;
                }
                else {
                    col--;
                }
                if (row == 0) {
                    row = grid.getRows() - 1;
                } else {
                    row--;
                }
            } //End search up and left
        }
    }
} 

int main() {
    Dictionary dict;

    dict.readFile();
    dict.selectionSort();
    dict.printVector();

    Grid grid("input30");
    
    findMatches(dict, grid);

    return 0;
}

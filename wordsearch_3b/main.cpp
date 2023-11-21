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
    //Declare Variables
    int maxLength = 15, minLength = 4; //Max and min lengths of words
    int l, row, col;
    string word;
    vector<vector<char>> matrix = grid.getMatrix();

    //For each element in the grid
    for (int r = 0; r < grid.getRows(); r++) {
        for (int c = 0; c < grid.getCols(); c++) {

            //Search the North Direction
            row = r, col = c; //Set row and col to current row and col
            word = ""; //Clear out the word
            //Add up to the maxLength of characters
            for (l = 0; l <= maxLength; l++) {
                //Add on the current character
                word += matrix[row][col];
                //If the word length is greater or equal to the min length 
                if (word.length() >= minLength) { 
                    //Look up the word and if it exists, print it out
                    if (dict.lookupWord(word)) {
                        cout << word << endl;
                    }
                }
                //If we are at the edge wrap, else iterate
                if (col == 0) {
                    col = grid.getCols() - 1;
                } else {
                    col--;
                }
            } //End North

            //Search the Northeast Direction
            row = r, col = c; //Set row and col to current row and col
            word = ""; //Clear out the word
                       //Add up to the maxLength of characters
            for (l = 0; l <= maxLength; l++) {
                //Add on the current character
                word += matrix[row] [col];
                //If the word length is greater or equal to the min length 
                if (word.length() >= minLength) {
                    //Look up the word and if it exists, print it out
                    if (dict.lookupWord(word)) {
                        cout << word << endl;
                    }
                }
                //If we are at the edge wrap, else iterate
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
            } //End Northeast

            //Search the East Direction
            row = r, col = c; //Set row and col to current row and col
            word = ""; //Clear out the word
                       //Add up to the maxLength of characters
            for (l = 0; l <= maxLength; l++) {
                //Add on the current character
                word += matrix[row][col];
                //If the word length is greater or equal to the min length 
                if (word.length() >= minLength) {
                    //Look up the word and if it exists, print it out
                    if (dict.lookupWord(word)) {
                        cout << word << endl;
                    }
                }
                //If we are at the edge wrap, else iterate
                if (row == grid.getRows() - 1) {
                    row = 0;
                } else {
                    row++;
                }
            } //End East

            //Search the Southeast Direction
            row = r, col = c; //Set row and col to current row and col
            word = ""; //Clear out the word
                       //Add up to the maxLength of characters
            for (l = 0; l <= maxLength; l++) {
                //Add on the current character
                word += matrix[row][col];
                //If the word length is greater or equal to the min length 
                if (word.length() >= minLength) {
                    //Look up the word and if it exists, print it out
                    if (dict.lookupWord(word)) {
                        cout << word << endl;
                    }
                }
                //If we are at the edge wrap, else iterate
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
            } //End Southeast

            //Search the South Direction
            row = r, col = c; //Set row and col to current row and col
            word = ""; //Clear out the word
                       //Add up to the maxLength of characters
            for (l = 0; l <= maxLength; l++) {
                //Add on the current character
                word += matrix[row][col];
                //If the word length is greater or equal to the min length 
                if (word.length() >= minLength) {
                    //Look up the word and if it exists, print it out
                    if (dict.lookupWord(word)) {
                        cout << word << endl;
                    }
                }
                //If we are at the edge wrap, else iterate
                if (col == grid.getCols() - 1) {
                    col = 0;
                } else {
                    col++;
                }
            } //End South

            //Search the Southwest Direction
            row = r, col = c; //Set row and col to current row and col
            word = ""; //Clear out the word
                       //Add up to the maxLength of characters
            for (l = 0; l <= maxLength; l++) {
                //Add on the current character
                word += matrix[row][col];
                //If the word length is greater or equal to the min length 
                if (word.length() >= minLength) {
                    //Look up the word and if it exists, print it out
                    if (dict.lookupWord(word)) {
                        cout << word << endl;
                    }
                }
                //If we are at the edge wrap, else iterate
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
            } //End Southwest

            //Search the West Direction
            row = r, col = c; //Set row and col to current row and col
            word = ""; //Clear out the word
                       //Add up to the maxLength of characters
            for (l = 0; l <= maxLength; l++) {
                //Add on the current character
                word += matrix[row][col];
                //If the word length is greater or equal to the min length 
                if (word.length() >= minLength) {
                    //Look up the word and if it exists, print it out
                    if (dict.lookupWord(word)) {
                        cout << word << endl;
                    }
                }
                //If we are at the edge wrap, else iterate
                if (row == 0) {
                    row = grid.getRows() - 1;
                } else {
                    row--;
                }
            } //End West

            //Search the Northwest Direction
            row = r, col = c; //Set row and col to current row and col
            word = ""; //Clear out the word
                       //Add up to the maxLength of characters
            for (l = 0; l <= maxLength; l++) {
                //Add on the current character
                word += matrix[row][col];
                //If the word length is greater or equal to the min length 
                if (word.length() >= minLength) {
                    //Look up the word and if it exists, print it out
                    if (dict.lookupWord(word)) {
                        cout << word << endl;
                    }
                }
                //If we are at the edge wrap, else iterate
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
            } //End Northwest

        } //End col iterator
    } //End row interator
} //End Find Matches     

int main() {
    Dictionary dict;

    dict.readFile();
    dict.quickSort(0, dict.getSize() - 1);
    dict.printVector();

    Grid grid("input15");
    // grid.printGrid();
    findMatches(dict, grid);

    return 0;
}

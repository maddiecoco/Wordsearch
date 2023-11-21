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
    int row = grid.getRows(); int col = grid.getCols(); 
    int i =0; int j = 0; int k =0;                       //various loop counters 
    int rowCount = 0; int colCount = 0;
    bool found;                                          //boolean type to check if word from the grid is found in the list
    vector<vector<char>> matrix = grid.getMatrix();                                  //n x n grid aka matrix, search in all 8 directions, use vectors?
    string wordn;
    string newWord;                                      //creating a word from grid
    string newLetter;                                    //pulling a letter from grid
    list<string> gridlist;                              //initialize list to store words from grid in
    list<string>::iterator itr = gridlist.begin();      //initialize iterator for gridlist to allow insertion

    if (row > col){int wordlength = row;}                //set the stored word length 
    else {int wordlength = col;}

    while(i<row) {                                        //checks each column iteratively 
        while(j<col){                                     //checks each row for every column

            //find all the words horizontal from start 
            while(rowCount <= row) {
                newLetter = matrix[rowCount][col];
                newWord = newWord + newLetter;
                gridlist.insert(itr, newWord);           //add the new string to the new word list 
                rowCount = rowCount + 1;        
                //if statement to allow for wrapping around
                if (rowCount > row){rowCount = 0;}
            }

            //find all the words vertically from start
            while(colCount <= col){
                newLetter = matrix[row][colCount];
                newWord = newWord + newLetter;
                gridlist.insert(itr, newWord);           //add new word to new list
                colCount = colCount + 1;
                //if statment to allow for wrapping around
                if (colCount > row){colCount = 0;}
            }

            //find all the words diagonally from start 
            while(rowCount <= row && colCount < col) {
                newLetter = matrix[rowCount][colCount];
                newWord = newWord + newLetter;
                gridlist.insert(itr, newWord);           //add new word to new list 
                rowCount = rowCount + 1;
                colCount = colCount + 1;
                //if statement to allow for wrapping around
                if (rowCount > row){rowCount = 0;}
                if (colCount > row){colCount = 0;}
            }
            j = j +1;
        }
        i = i+1;
    }
    for (string k : gridlist)
        found = dict.lookupWord(k);      //check to see if the word in gridlist is found in wordlist
        if(!found)
        {
        gridlist.remove(wordn);                         //remove any words not found in wordlist from gridlist
        }                                   //next word to look up
    

    //output gridlist                                          
    cout << "List of words from the dictionary found in the grid:";
    for (string word : gridlist) 
    {
        cout << word << endl;
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

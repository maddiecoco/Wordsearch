// Created by madelinecoco on 11/08/2023.
// The Card class represents a card with a value and a suit.

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector> 

using namespace std;

// Part A: Card class
class Dictionary {

public:
    void readFile();
    void printVector();
    void selectionSort();
    bool lookupWord(string target);
    int getSize();
private:
    vector<string> words;
};

#endif //DICTIONARY_H
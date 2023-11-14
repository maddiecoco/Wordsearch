// Created by nehae on 10/18/2023.
// The Main file demonstrates creating a deck, printing it, shuffling it, and then printing the shuffled deck.


#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "dictionary.h"
#include "grid.h"

int main() {
    Dictionary dict;

    // dict.readFile();
    // dict.selectionSort();
    // dict.printVector();

    Grid grid("input15");
    grid.printGrid();

    return 0;
}

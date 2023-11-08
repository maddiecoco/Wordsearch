#include "dictionary.h"
#include <fstream>

void Dictionary::readFile()
{
     // Read file and add words line by line to 'words' vector
    string temp;
    ifstream infile;
    infile.open("Dictionary"); // Put path of file in quotes
    if(!infile)
    {
        cerr << "Couldn't open Dictionary file, check path" << endl;
    }
    while (getline(infile, temp))
    {
        words.push_back(temp);
    }
}

void Dictionary::printVector()
{
    for(int i = 0; i < words.size(); i++)
    {
        cout << words[i] << endl;
    }
}
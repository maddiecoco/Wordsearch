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

void Dictionary::selectionSort()
{
    // Sort word vector using selection sort
    for (int i = 0; i < words.size()-1; i++)
    {
        int min = i;
        for (int j = i+1; j < words.size(); j++)
        {
            if (words[j] < words[min])
            {
                min = j;
            }
        }
        swap(words[i], words[min]);
    }
}

int Dictionary::getSize()
{
    return words.size();
}

bool Dictionary::lookupWord(string target)
// Look for target word in alphabetical list using binary search method
{
    int left, right, mid;
    left = 0;
    right = words.size() - 1;

    while (left <= right) {
        mid = (left + right) / 2;
        if (words[mid] == target) { 
            return true;
        }
        else if (words[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false; //Word is not in list
}
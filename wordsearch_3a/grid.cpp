#include "grid.h" // Includes the header for the Grid class

Grid::Grid(const string& fileName)
{  
    // Constructor for the grid class, takes in the grid text file name
    std::ifstream infile(fileName);

    // Check if the file is open, if not, print an error and return
    if (!infile.is_open()) 
    {
        cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    // Read rows and columns from the file
    infile >> rows >> cols;

    // Resize the matrix to fit the specified number of rows and columns
    matrix.resize(rows, std::vector<char>(cols));

    // Read letters into the matrix from the file
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            infile >> matrix[i][j];
        }
    }

    // Close the file after reading
    infile.close();
}

void Grid::printGrid() const {
    // Prints the matrix representing the grid
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<char>> Grid::getMatrix()
{
    // Returns the matrix data structure containing the grid
    return matrix;
}

int Grid::getRows()
{
    // Returns the number of rows in the grid
    return rows;
}

int Grid::getCols()
{
    // Returns the number of columns in the grid
    return cols;
}

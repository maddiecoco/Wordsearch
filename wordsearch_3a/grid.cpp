 #include "grid.h"
 
Grid::Grid(const string& fileName)
{  
    // Constructor for the grid class, takes in the grid text file name
    std::ifstream infile(fileName);

    if (!infile.is_open()) 
    {
        cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    // Read rows and columns from the file
    infile >> rows >> cols;

    // Resize the matrix for the provided dimensions
    matrix.resize(rows, std::vector<char>(cols));

    // Read letters into the matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            infile >> matrix[i][j];
        }
    }

    infile.close();
}

void Grid::printGrid() const {
    // Prints the matrix created for the grid input
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
    return matrix;
}

int Grid::getRows()
{
    return rows;
}

int Grid::getCols()
{
    return cols;
}


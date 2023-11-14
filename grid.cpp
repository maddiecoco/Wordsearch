 #include "grid.h"
 
Grid::Grid(const string& fileName)
{
    std::ifstream infile(fileName);

    if (!infile.is_open()) 
    {
        cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    // Read rows and columns from the file
    infile >> rows >> cols;

    // Resize the matrix accordingly
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
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


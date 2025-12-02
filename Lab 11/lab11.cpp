#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>  // for std::setw and std::setfill
#include <stdexcept> // for std::out_of_range

using namespace std;

class Matrix {
private:
    int size;
    vector<vector<int>> data;

public:
    // Constructor that takes matrix size
    Matrix(int n) : size(n), data(n, vector<int>(n)) {}

    // Read matrix data from file
    void readFromFile(ifstream& file) {

        // Read the first matrix
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                file >> data[i][j];
            }
        }

    }

    // Display matrix with aligned columns
    void display() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << setw(3) << setfill('0') << data[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Operator overloading for matrix addition
    Matrix operator+(const Matrix& other) const {
        if (size != other.size) {
            throw invalid_argument("Matrices must have the same size for addition.");
        }
        Matrix result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Operator overloading for matrix multiplication
    Matrix operator*(const Matrix& other) const {
        if (size != other.size) {
            throw invalid_argument("Matrices must have the same size for multiplication.");
        }
        Matrix result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < size; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Calculate the sum of the diagonals
    int diagonalSum() const {
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += data[i][i];                  // Main diagonal
            sum += data[i][size - i - 1];       // Secondary diagonal
        }
        return sum;
    }

    // Swap rows
    Matrix swapRows(int row1, int row2) const {
        if (row1 < 0 || row1 >= size || row2 < 0 || row2 >= size) {
            throw out_of_range("Row indices out of range.");
        }
        Matrix result = *this;  // Copy of the current matrix
        swap(result.data[row1], result.data[row2]);
        return result;
    }

    // Swap columns
    Matrix swapColumns(int col1, int col2) const {
        if (col1 < 0 || col1 >= size || col2 < 0 || col2 >= size) {
            throw out_of_range("Column indices out of range.");
        }
        Matrix result = *this;  // Copy of the current matrix
        for (int i = 0; i < size; ++i) {
            swap(result.data[i][col1], result.data[i][col2]);
        }
        return result;
    }

    // Update matrix element
    Matrix update(int row, int col, int value) const {
        if (row < 0 || row >= size || col < 0 || col >= size) {
            throw out_of_range("Matrix indices out of range.");
        }
        Matrix result = *this;  // Copy of the current matrix
        result.data[row][col] = value;
        return result;
    }
};

int main() {
    int size;

    ifstream file("input.txt");
    if (!file.is_open()) {
        throw runtime_error("Error opening file.");
    }

    file >> size; // Read the size of the matrix

    Matrix matrix1(size);
    Matrix matrix2(size);
    
    matrix1.readFromFile(file);  // Read from input.txt
    matrix2.readFromFile(file);
    file.close(); //close the file after reading

    cout << "Matrix 1:" << endl;
    matrix1.display();

    cout << "Matrix 2:" << endl;
    matrix2.display();

    // Add two matrices
    Matrix resultAdd = matrix1 + matrix2;  // Using overloaded + operator
    cout << "Matrix 1 + Matrix 2:" << endl;
    resultAdd.display();

    // Multiply two matrices
    Matrix resultMul = matrix1 * matrix2;  // Using overloaded * operator
    cout << "Matrix 1 * Matrix 2:" << endl;
    resultMul.display();

    // Diagonal sum
    cout << "Diagonal sum of Matrix 1: " << matrix1.diagonalSum() << endl;

    // Swap rows 0 and 1
    Matrix swappedRows = matrix1.swapRows(0, 1);
    cout << "Matrix 1 after swapping rows 0 and 1:" << endl;
    swappedRows.display();

    // Swap columns 0 and 1
    Matrix swappedCols = matrix1.swapColumns(0, 1);
    cout << "Matrix 1 after swapping columns 0 and 1:" << endl;
    swappedCols.display();

    // Update element (row 0, col 0)
    Matrix updatedMatrix = matrix1.update(0, 0, 100);
    cout << "Matrix 1 after updating (0, 0) to 100:" << endl;
    updatedMatrix.display();

    return 0;
}

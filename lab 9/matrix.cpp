#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <utility>
using namespace std;

vector<string> split(const string& str) {
    vector<string> tokens; // Vector to hold the split substrings
    stringstream ss(str); // Create a stringstream from the input string

    string token;
    while (getline(ss, token, ' ')) { // Read until the delimiter is found
        tokens.push_back(token); // Add the token to the vector
    }

    return tokens; // Return the vector of tokens
}

auto buildInput(const string& filename) {
    fstream File(filename);
    array<vector<vector<string>>, 2> matrices;

    if (!File.is_open()) {
        cout << "Couldn't open " << filename << endl;
        return matrices;
    }

    string size_str;
    if (!getline(File, size_str)) {
        cout << "Reading first line error" << endl;
    }
    int size = stoi(size_str);

    string line;
    for (size_t j = 0; j < 2; j++)
    {
        vector<vector<string>> matrix;
        for (size_t i = 0; i < size; i++)
        {
            if (!getline(File, line)) {
                cout << "Not enough lines" << endl;
                return matrices;
            }
            if (line.length() <= 1) {
                i--;
                continue;
            }
            matrix.push_back(split(line));
        }
        matrices[j] = matrix;
    }

    return matrices;
}

void print(vector<vector<string>> matrix) {
    for (size_t i = 0; i < matrix.size(); i++)
    {
        const auto& row = matrix[i];
        for (size_t j = 0; j < row.size(); j++)
        {
            cout << row[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

auto add(vector<vector<string>> a, vector<vector<string>> b) {
    cout << "Adding matrices:" << endl;
    vector<vector<string>> matrix;
    for (size_t i = 0; i < a.size(); i++)
    {
        vector<string> row;
        for (size_t j = 0; j < a.size(); j++)
        {
            row.push_back(to_string(stoi(a[i][j]) + stoi(b[i][j])));
        }
        matrix.push_back(row);
    }
    print(matrix);
    return matrix;
}

auto multiply(vector<vector<string>> a, vector<vector<string>> b) {
    cout << "Multiplying matrices:" << endl;
    vector<vector<string>> matrix;
    for (size_t i = 0; i < a.size(); i++)
    {
        vector<string> row;
        for (size_t j = 0; j < a.size(); j++)
        {
            int prod = 0;
            for (size_t k = 0; k < a.size(); k++)
            {
                prod+= (stoi(a[i][k]) * stoi(b[k][j]));
            }
            row.push_back(to_string(prod));
        }
        matrix.push_back(row);
    }
    print(matrix);
    return matrix;
}

void diagonalSum(vector<vector<string>> a) {
    cout << "Printing diagonal sum: " << endl;
    int sum = 0;
    for (size_t i = 0; i < a.size(); i++)
    {
        for (size_t j = 0; j < a.size(); j++)
        {
            if (i == j || i == a.size() - j -1) {
                sum+= stoi(a[i][j]);
            }
        }
    }
    cout << "Main and secondary diagonal sum: " << sum << endl;
    cout << endl;
}

auto rowSwap(vector<vector<string>> a, int swap1, int swap2) {
    cout << "Printing row swap: " << endl;
    if (!((0 <= swap1 && swap1 < a.size()) && (0 <= swap2 && swap2 < a.size()))) {
        cout << "Error: out of bounds on rowSwap" << endl;
        return a;
    }
    swap(a[swap1], a[swap2]);
    print(a);
    return a;
}

auto colSwap(vector<vector<string>> a, int swap1, int swap2) {
    cout << "Printing column swap: " << endl;
    if (!((0 <= swap1 && swap1 < a.size()) && (0 <= swap2 && swap2 < a.size()))) {
        cout << "Error: out of bounds on colSwap" << endl;
        return a;
    }

    for (size_t i = 0; i < a.size(); i++)
    {
        swap(a[i][swap1], a[i][swap2]);
    }

    print(a);
    return a;
}

auto valueUpdate(vector<vector<string>> a, int row, int col, int value) {
    cout << "Printing value update: " << endl;
    if (!((0 <= row && row < a.size()) && (0 <= col && col < a.size()))) {
        cout << "Error: out of bounds on valueUpdate" << endl;
        return a;
    }

    a[row][col] = to_string(value);
    print(a);
    return a;
}

int main() {
    string filename = "input.txt";
    auto matrices = buildInput(filename); //create file

    auto matrix1 = matrices[0];
    auto matrix2 = matrices[1];
    print(matrix1);
    print(matrix2);

    add(matrix1, matrix2);
    multiply(matrix1, matrix2);
    diagonalSum(matrix1);
    rowSwap(matrix1, 2, 3);
    colSwap(matrix1, 1, 3);
    valueUpdate(matrix1, 0, 0, 1000);

    return 0;
} 
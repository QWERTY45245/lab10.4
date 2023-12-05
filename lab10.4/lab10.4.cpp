#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

// Функція для зчитування матриці з файлу
vector<vector<int>> readMatrixFromFile(const string& qq, int& n, int& m) {
    ifstream file(qq);

    if (!file.is_open()) {
        cerr << "Unable to open the file: " << qq << endl;
        exit(EXIT_FAILURE);
    }

    file >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            file >> matrix[i][j];
        }
    }

    file.close();
    return matrix;
}

// Функція для знаходження максимального значення в кожному рядку матриці
vector<int> findMaxInEachRow(const vector<vector<int>>& matrix) {
    vector<int> maxValues;

    for (const auto& row : matrix) {
        int maxVal = numeric_limits<int>::min();
        for (int val : row) {
            if (val > maxVal) {
                maxVal = val;
            }
        }
        maxValues.push_back(maxVal);
    }

    return maxValues;
}

// Функція для запису результатів у новий файл
void writeResultsToFile(const string& ww, const vector<int>& maxValues, int n, int m) {
    ofstream file(ww);

    if (!file.is_open()) {
        cerr << "Unable to open the file: " << ww << endl;
        exit(EXIT_FAILURE);
    }

    file << n << " " << m << endl;

    for (int i = 0; i < n; ++i) {
        file << maxValues[i] << " ";
        for (int j = 0; j < m; ++j) {
            file << maxValues[i] << " ";
        }
        file << endl;
    }

    file.close();
}

int main() {
    string inputFileName, outputFileName;
    int n, m;

    // Користувач вводить імена файлів та розмірності матриці
    cout << "Enter the input filename: ";
    cin >> inputFileName;

    // Зчитуємо матрицю з файлу
    vector<vector<int>> matrix = readMatrixFromFile(inputFileName, n, m);

    // Знаходимо максимальні значення в кожному рядку
    vector<int> maxValues = findMaxInEachRow(matrix);

    // Користувач вводить ім'я файлу для результатів
    cout << "Enter the output filename: ";
    cin >> outputFileName;

    // Записуємо результати у новий файл
    writeResultsToFile(outputFileName, maxValues, n, m);

    cout << "Results written to " << outputFileName << endl;

    return 0;
}
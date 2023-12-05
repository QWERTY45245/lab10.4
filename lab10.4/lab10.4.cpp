#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

// ������� ��� ���������� ������� � �����
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

// ������� ��� ����������� ������������� �������� � ������� ����� �������
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

// ������� ��� ������ ���������� � ����� ����
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

    // ���������� ������� ����� ����� �� ��������� �������
    cout << "Enter the input filename: ";
    cin >> inputFileName;

    // ������� ������� � �����
    vector<vector<int>> matrix = readMatrixFromFile(inputFileName, n, m);

    // ��������� ���������� �������� � ������� �����
    vector<int> maxValues = findMaxInEachRow(matrix);

    // ���������� ������� ��'� ����� ��� ����������
    cout << "Enter the output filename: ";
    cin >> outputFileName;

    // �������� ���������� � ����� ����
    writeResultsToFile(outputFileName, maxValues, n, m);

    cout << "Results written to " << outputFileName << endl;

    return 0;
}
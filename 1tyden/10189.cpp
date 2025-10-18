#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Field {
    int rows = 0, cols = 0;
    vector<string> grid;
};


const int dx[8] = {-1,-1,-1,0,0,1,1,1};
const int dy[8] = {-1,0,1,-1,1,-1,0,1};


int countMines(const Field &field, int x, int y) {
    int count = 0;
    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < field.rows && ny >= 0 && ny < field.cols) {
            if (field.grid[nx][ny] == '*') count++;
        }
    }
    return count;
}


vector<string> solveField(const Field &field) {
    vector<string> result = field.grid;
    for (int i = 0; i < field.rows; i++) {
        for (int j = 0; j < field.cols; j++) {
            if (field.grid[i][j] == '.') {
                result[i][j] = char('0' + countMines(field, i, j));
            }
        }
    }
    return result;
}

int main() {
    int rows, cols;
    int fieldNumber = 1;
    bool first = true;

    while (cin >> rows >> cols) {
        if (rows == 0 && cols == 0) break;

        Field field;
        field.rows = rows;
        field.cols = cols;
        field.grid.resize(rows);

        for (int i = 0; i < rows; i++) {
            cin >> field.grid[i];
        }

        if (!first) cout << "\n";
        first = false;

        cout << "Field #" << fieldNumber++ << ":\n";
        vector<string> solved = solveField(field);
        for (const string &row : solved) {
            cout << row << "\n";
        }
    }
    return 0;
}

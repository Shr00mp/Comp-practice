#include <bits/stdc++.h>
using namespace std;

// CSES Problem Set - Counting Rooms 

vector<vector<char>> building;
vector<vector<bool>> visited;
int n, m;

void floodfill(int row, int col) {
    if (row >= n || col >= m || row < 0 || col < 0) {
        // index out of bounds
        return;
    } else if (visited[row][col] || building[row][col] == '#') {
        return;
    } else if (building[row][col] == '.') {
        visited[row][col] = true;
        floodfill(row+1, col); floodfill(row-1, col);
        floodfill(row, col+1); floodfill(row, col-1);
        return;
    }
    
}

int main() {
    int num_rooms = 0;
    cin >> n >> m;
    building = vector<vector<char>>(n, vector<char>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));

    // Take inputs
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> building[i][j];
            if (building[i][j] == '#') {
                visited[i][j] = true;
            }
        }
    }

    // Perform a flood fill
    for (int r=0; r<n; r++) {
        for (int c=0; c<m; c++) {
            if (!visited[r][c]) {
                num_rooms++;
                floodfill(r, c);
            }
        }
    }

    cout << num_rooms;
}

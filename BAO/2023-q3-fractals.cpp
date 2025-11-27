#include <bits/stdc++.h>
using namespace std;
#include <cmath>

int binary_to_denary(vector<int> binary_num) {
    long long denary_num = 0;
    int power=0; 
    int digit;
    for (int i=binary_num.size()-1; i>=0; i--) {
        digit = binary_num[i];
        denary_num += digit * pow(2, power);
        power++;
    }
    return denary_num;
}

vector<vector<int>> generate_new(vector<vector<int>> prev_grid, int n) {
    vector<vector<int>> new_grid = vector<vector<int>>(pow(2, n-1));
    // First, we can create the empty grid by setting the length of each vector (i.e. row)
    for (int i=0; i<pow(2, n-1); i++) {
        new_grid[i] = vector<int>(i+1, -1);
        // All initial values are initialised to -1
    }
    // (1) Add the top triangle
    for (int j=0; j<prev_grid.size(); j++) {
        new_grid[j] = prev_grid[j];
    }
    // (2) Add the right triangle - erroring out here?? 
    int prev_grid_row;
    for (int k=prev_grid.size(); k<new_grid.size(); k++) {
        // k represents the row of the new grid that we are adding to 
        prev_grid_row = k - prev_grid.size();
        // Iterate through values in prev_grid row and add them to new_grid[k]
        for (int u=0; u<prev_grid[prev_grid_row].size(); u++) {
            new_grid[k][u] = prev_grid[prev_grid_row][u];
        }
    }
    // (3) Add the left triangle
    int new_grid_index;
    for (int p=prev_grid.size(); p<new_grid.size(); p++) {
        // p represents hte row of the new grid that we are adding to
        prev_grid_row = p - prev_grid.size();
        new_grid_index = new_grid[p].size()-1;
        for (int o=prev_grid[prev_grid_row].size()-1; o>=0; o--) {
            // o is index of right <-- left elements in prev_grid[prev_grid_row]
            // We also need the corresponding digit in new_grid[p]
            new_grid[p][new_grid_index] = prev_grid[prev_grid_row][o];
            new_grid_index--;
        }
    }

    // (4) Add the 0s in the middle
    for (int row=prev_grid.size(); row<new_grid.size(); row++) {
        for (int row_index=0; row_index<new_grid[row].size(); row_index++) {
            if (new_grid[row][row_index] == -1) {
                new_grid[row][row_index] = 0;
            }
        }
    }
    return new_grid;
}

int part_b() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        return 1;
    }
    vector<vector<int>> previous = vector<vector<int>>(1, vector<int>(1, 1));
    for (int i=2; i<=n; i++) {
        vector<vector<int>> new_grid = generate_new(previous, i);
        previous = new_grid;
    }
    int ans = binary_to_denary(previous[k-1]);
    return ans;
}

void part_c() {
    // I - This is false because they are instead scaled by a factor of 1/2

    // II - This is true because each time, the number of black triangles
    // on the base is doubled. The sequence starts with number of black triangles = 1
    // so will always end up being an integer power of 2

    // III - This is true because (explanation written on paper)
}

void part_d() {
    // (i) In every iteration, for every separate tetrahedron, a triangle from each of the 4 faces
    // is removed, but the surface area of that triangle is made up for by the 4 extra faces
    // created after removing the middle tetrahedron.
    // More rigorous mathematical proof on paper
    // Constant surface area = L^2 * sqrt(3)
}

int main() {
    int ans = part_b();
    cout << ans;
}

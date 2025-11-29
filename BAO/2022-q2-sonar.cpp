#include <bits/stdc++.h>
using namespace std;
#include <cmath>
#include <algorithm>

int p, x_start, y_start;

void block_charges(int x, int y, vector<vector<bool>> &contains_charge) {
    int k=1;
    int x_change = x - x_start;
    int y_change = y - y_start;
    while (true) {
        if (0 <= y_start + (k*y_change) && y_start + (k*y_change) <= p) {
            if (0 <= x_start + (k*x_change) &&  x_start + (k*x_change) <= p) {
                contains_charge[y_start+(k*y_change)][x_start + (k*x_change)] = true;
            } else {
                break;
            }
        } else {
            break;
        }
        k++;
    }
}

int part_a() {
    cin >> p >> x_start >> y_start;
    y_start = p - y_start; // top left is now (0, 0)
    vector<vector<bool>> contains_charge(p+1, vector<bool>(p+1, false));
    contains_charge[y_start][x_start] = true;
    // Strategy is to iterate through surrounding grid points first
    // When we deploy a charge, we block all other charges along that line
    // by iterating through all locations with same gradient 
    // If at any point in the grid, the vertex is not blocked, then we place a charge
    long long num_charges = 0;
    int min_x, min_y, max_x, max_y;
    min_x = x_start;
    max_x = x_start;
    min_y = y_start;
    max_y = y_start;
    while (true) {
        min_x = max(0, min_x-1);
        max_x = min(p, max_x+1);
        min_y = max(0, min_y-1);
        max_y = min(p, max_y+1);
        // Iterate through all y=min_y
        for (int x=min_x; x<=max_x; x++) {
            if (!contains_charge[min_y][x]) {
                num_charges++;
                block_charges(x, min_y, contains_charge);
            }
        } 
        // Iterate through all y=max_y
        for (int x=min_x; x<=max_x; x++) {
            if (!contains_charge[max_y][x]) {
                num_charges++;
                block_charges(x, max_y, contains_charge);
            }
        }
        // Iterate through min_x
        for (int y=min_y; y<=max_y; y++) {
            if (!contains_charge[y][min_x]) {
                num_charges++;
                block_charges(min_x, y, contains_charge);
            }
        }
        // Iterate through all max_x
        for (int y=min_y; y<=max_y; y++) {
            if (!contains_charge[y][max_x]) {
                num_charges++;
                block_charges(max_x, y, contains_charge);
            }
        }
        if (min_x==0 && min_y==0 && max_x==p && max_y==p) {
            break;
        }
    }
    return num_charges;
}

int main() {
    int num_charges = part_a();
    cout << num_charges;
}

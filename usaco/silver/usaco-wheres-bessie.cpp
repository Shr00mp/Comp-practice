#include <bits/stdc++.h>
using namespace std;

// USACO 2017 US Open Contest, Silver P3. Where's Bessie?

int N;
vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<vector<int>> pcls;
vector<char> colours(2);

bool within_another_pcl(int top_left_r, int top_left_c, int bottom_right_r, int bottom_right_c) {
    int top_left_r_pcl, top_left_c_pcl, bottom_right_r_pcl, bottom_right_c_pcl;
    for (vector<int> pcl: pcls) {
        top_left_r_pcl = pcl[0];
        top_left_c_pcl = pcl[1];
        bottom_right_r_pcl = pcl[2];
        bottom_right_c_pcl = pcl[3];
        if (top_left_r >= top_left_r_pcl &&
        top_left_c >= top_left_c_pcl &&
        bottom_right_r <= bottom_right_r_pcl &&
        bottom_right_c <= bottom_right_c_pcl) {
            return true;
        }
    }
    return false;
}

void flood_fill(int r, int c, int colour) {
    if (grid[r][c]!=colour) {
        return;
    } else if (r > N || r < 0 || c > N || c < 0) {
        return;
    } else if (visited[r][c]) {
        return;
    }
    visited[r][c] = true;
    flood_fill(r+1, c, colour); flood_fill(r-1, c, colour);
    flood_fill(r, c+1, colour); flood_fill(r, c-1, colour);
}

bool is_pcl(int top_left_r, int top_left_c, int bottom_right_r, int bottom_right_c) {
    colours = vector<char>(2, ' ');
    int colour1_floods = 0;
    int colour2_floods = 0;
    visited = vector<vector<bool>>(N, vector<bool>(N, false));
    for (int r=top_left_r; r<=bottom_right_r; r++) {
        for (int c=top_left_c; c<=bottom_right_c; c++) {
            if (visited[r][c]) {continue;}
            if (colour1_floods > 1 && colour2_floods > 1) {
                return false; 
            }
            if (colours[0] == ' ') {
                colours[0] = grid[r][c];
                colour1_floods = 1;
                visited[r][c] = true;
                flood_fill(r, c, grid[r][c]);
            } else if (grid[r][c] == colours[0]) {
                colour1_floods++;
                visited[r][c] = true;
                flood_fill(r, c, grid[r][c]);
            } else if (grid[r][c] = colours[2]) {
                colour2_floods++;
                visited[r][c] = true;
                flood_fill(r, c, grid[r][c]);
            } else if (colours[1] == ' ') {
                colours[1] = grid[r][c];
                colour2_floods = 1;
                visited[r][c] = true;
                flood_fill(r, c, grid[r][c]);
            } else {return false;}
        }
    }
    if (colour1_floods != 1 && colour2_floods != 1) {return false;}
    else if (colour1_floods == 1 && colour2_floods == 0) {return false;}
    else {return true;}
}

int main() {
    cin>>N;
    grid = vector<vector<char>>(N, vector<char>(N));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> grid[i][j];
        }
    }
    
    // Choose which rectangle to consider by considering top left and bottom right corners
    // Perform flood fill algorithm in order to check if square is ok
    // Keep a list of PCLs that we have already found so that we can check if smaller ones are in it
    
    // Here, we need to iterate through all possible rectangles
    for (int top_left_r=0; top_left_r<=N; top_left_r++) {
        for (int top_left_c=0; top_left_c<=N; top_left_c++) {
            
        }
    }
}

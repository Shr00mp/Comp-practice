#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>
#include <set>

int main() {
    int N; cin >> N;
    vector<vector<char>> symbol_chart(N, vector<char>(N, ' ')); 
    int M; cin >> M;
    char curr_symbol;
    for (int row=0; row<N; row++) {
        for (int col=0; col<row+1; col++) {
            cin >> curr_symbol;
            symbol_chart[row][col] = curr_symbol;
            if (curr_symbol == 'D') {symbol_chart[col][row] = 'D';}
            else if (curr_symbol == 'W') {symbol_chart[col][row] = 'L';}
            else if (curr_symbol == 'L') {symbol_chart[col][row] = 'W';}  
        }
    }

    int left, right;
    vector<int> available_left;
    vector<int> available_both; 
    int count = 0;
    for (int game=0; game<M; game++) {
        cin >> left >> right; left --; right--;
        for (int col_left=0; col_left<N; col_left++) {
            if (symbol_chart[left][col_left] == 'L') {
                available_left.push_back(col_left);
            }
        }
        if (left != right) {
            for (int col_right=0; col_right<N; col_right++) {
            if (symbol_chart[right][col_right] == 'L') {
                if (find(available_left.begin(), available_left.end(), col_right) != available_left.end()) {
                    available_both.push_back(col_right);
                }
            }
        }
        }
        else {
            available_both = available_left;
        }
        
        int num_chosen = available_both.size();
        int num_not_chosen = N - num_chosen;

        count = (num_chosen * N) + (num_not_chosen * num_chosen);

        cout << count << endl;
        available_left.clear();
        available_both.clear();
    }
}
 
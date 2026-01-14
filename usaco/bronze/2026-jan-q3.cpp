#include <bits/stdc++.h>
using namespace std;
#include <algorithm>


int main() {
    long long N, K, Q;
    cin >> N >> K >> Q;
    long long r, c, v;
    vector<vector<long long>> field(N+1, vector<long long>(N+1, 0));
    vector<vector<long long>> pictures(N-K+1, vector<long long>(N-K+1, 0));
    
    for (int i=0; i<Q; i++) {
        cin >> r >> c >> v;
        r--;
        c--;

        long long increase_amount = v - field[r][c];
        field[r][c] = v;

        int row_start = max((long long) 0, r-K+1);
        int row_end = min((long long) r, N-K+1-1);
        int col_start = max((long long) 0, c-K+1);
        int col_end = min(c, N-K+1-1);

        for (int i = row_start; i <= row_end; i++) {
            for (int j = col_start; j <= col_end; j++) {
                pictures[i][j] += increase_amount;
            }
        }

        // find max sum for a pic
        long long max_sum = 0;
        for (int i = 0; i < N-K+1; i++) {
            for (int j = 0; j < N-K+1; j++) {
                max_sum = max((long long)max_sum, (long long) pictures[i][j]);
            }
        }

        cout << max_sum << "\n";
    }
}

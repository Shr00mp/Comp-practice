#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);

    int K, N;
    int curr_cow;
    cin >> K >> N;
    vector<vector<bool>> result_matrix(N, vector<bool>(N, true));
    vector<int> curr_vector(N, 0);
    for (int i=0; i<K; i++) {
        for (int j=0; j<N; j++) {
            cin >> curr_vector[j];
        }

        // Now, need a for loop in a for loop :(
        for (int x=1; x<N; x++) {
            curr_cow = curr_vector[x];
            for (int y=0; y<x; y++) {
                result_matrix[curr_cow-1][curr_vector[y]-1] = false;
            }
        }
    }

    int total = 0;
    // Count how many entries are still true
    for (vector<bool> row : result_matrix) {
        for (bool element : row) {
            if (element) {
                total += 1;
            }
        }
    }

    total -= N; 

    cout << total;
} 
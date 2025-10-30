#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("div7.in", "r", stdin);

    int N; 
    cin >> N;

    // Use long long for the prefix sum array
    long long p_sum[N+1];
    p_sum[0] = 0;
    long long new_num;

    for (int i = 1; i <= N; i++) {
        if (i == 1) {
            cin >> p_sum[1];
            continue;
        }
        cin >> new_num;
        p_sum[i] = p_sum[i-1] + new_num;
    }

    int largest_range = 0;
    long long right_value;

    for (int r = 1; r <= N; r++) {
        right_value = p_sum[r];
        for (int l = 0; l < r; l++) {
            if ((right_value - p_sum[l]) % 7 == 0) {
                if (r - l > largest_range) {
                    largest_range = r - l;
                }
                break;
            }
        }
    }
    freopen("div7.out", "w", stdout);
    cout << largest_range;
}

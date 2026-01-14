#include <bits/stdc++.h>
using namespace std;

long long get_x(vector<long long> test_case) {
    long long A, B, ca, cb, fa;
    A = test_case[0];
    B = test_case[1];
    ca = test_case[2];
    cb = test_case[3];
    fa = test_case[4];

    long long needs_A = fa - A;
    if (needs_A <= 0) {
        return 0LL;
    }
    long long x = 0; 
    if (cb < ca) {
        // wait we have to trasfer all B over to A first. 
        long long poss_num_exchanges = B / cb;
        long long A_sum = A + (poss_num_exchanges * ca);
        long long needs_A_1 = max(0LL, fa - A_sum);
        if (needs_A_1 != 0LL) {
            x += needs_A_1;
            x += (cb - 1);
        } 
    } else {
        long long num_exchanges = (needs_A + ca - 1) / ca; // ceil
        long long needs_B = num_exchanges * cb; 
        x += max(needs_B - B, 0LL);
        if (x != 0LL) {
            long long actual_end_A = A + (num_exchanges * ca);
            long long before_last_transfer = actual_end_A - ca;
            x += max(0LL, fa - 1 - before_last_transfer);
        } 
    }
    return x;
}

int main() {
    long long T; cin >> T;
    vector<vector<long long>> test_cases(T, vector<long long>(5, 0));
    long long A, B, ca, cb, fa;
    for (int i=0; i<T; i++) {
        cin >> test_cases[i][0];
        cin >> test_cases[i][1];
        cin >> test_cases[i][2];
        cin >> test_cases[i][3];
        cin >> test_cases[i][4];
    }

    for (vector<long long> t: test_cases) {
        cout << (long long) get_x(t) << "\n";
    }
} 
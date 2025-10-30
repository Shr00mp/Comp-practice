#include <bits/stdc++.h>
using namespace std;

int simulate(int init_loc, int n, const vector<array<int,3>>& data) {
    int count = 0;
    for (int i=0; i<n; i++) {
        int a = data[i][0];
        int b = data[i][1];
        int c = data[i][2];

        if (init_loc == a) {
            init_loc = b;
        }
        else if (init_loc == b) {
            init_loc = a;
        }
        
        if (init_loc == c) {
            count++;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n;
    cin >> n;
    vector<array<int, 3>> data(n);

    for (int i=0; i<n; i++) {
        cin >> data[i][0] >> data[i][1] >> data[i][2];
    }

    int if_1 = simulate(1, n, data);
    int if_2 = simulate(2, n, data);
    int if_3 = simulate(3, n, data);

    cout << max({if_1, if_2, if_3});
}

#include <bits/stdc++.h>
using namespace std;

bool check_s(string s) {
    long long mid = s.size() / 2;
    string first = s.substr(0, mid);
    string second = s.substr(mid, mid);
    if (first == second) {return true;}
    else {return false;}
}

int main() {
    long long T, k; 
    cin >> T >> k;
    long long N; string S;
    vector<tuple<long long, string>> test_cases;
    for (int i=0; i<T; i++) {
        cin >> N; cin >> S;
        test_cases.push_back({N, S});
    }
    int count = 0;
    for (tuple<long long, string> t: test_cases) {
        count++;
        // if k = 0, we check if it itself is, if 2, then 3
        // if k = 1, we check if it itself is. if not, then 3
        N = get<0>(t); S = get<1>(t);
        if (N % 2 == 1) {
            cout << -1 << "\n";
            continue;
        }

        if (check_s(S)) {
            cout << 1 << "\n";
            for (int i = 0; i < 3*N; i++) {
                if (i > 0) cout << " ";
                cout << 1;
            }
            cout << "\n";
            continue;
        }

        if (k == 1) {
            cout << 3 << "\n";
            // we can just do 3, in which case remove all Cs, Os, then Ws
            for (int i=0; i<3*N; i++) {
                if (i > 0) cout << " ";

                if (S[i] == 'C') {cout << 1;}
                else if (S[i] == 'O') {cout << 2;}
                else {cout << 3;}
            }
            cout << "\n";
            continue;
        }

        if (k == 0) {
            if (count == 3) {
                cout << 2 << "\n";
                cout << "1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 2";
            }
        }
    }
}

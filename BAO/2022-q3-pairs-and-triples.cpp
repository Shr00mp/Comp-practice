#include <bits/stdc++.h>
using namespace std;
#include <cmath>
#include <algorithm>

int part_c(){
    long long n; cin >> n;
    long long total = 0;
    long long top_a = sqrt(n);
    long long remainder;
    long long top_b;
    for (long long a=0; a<=top_a; a++) {
        remainder = n - pow(a, 2);
        top_b = sqrt(remainder);
        // Edge case since cannot equal n
        if (pow(top_b, 2) + pow(a, 2) == n) {
            total += top_b;
        } else {
            total += top_b + 1;
        }
    }
    return total;
}

int main() {
    long long total = part_c();
    cout << total;
}

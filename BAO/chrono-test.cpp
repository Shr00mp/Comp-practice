#include <bits/stdc++.h>
using namespace std;
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    auto start = chrono::steady_clock::now();
    for (long long i=0; i>=0; i++) {
        auto now = chrono::steady_clock::now();
        chrono::duration<double> elapsed = now-start;
        if (elapsed.count() >= 1.0) {
            cout << "One second reached" << "\n";
            cout << i;
            goto end;
        }
    }
    end:;
}

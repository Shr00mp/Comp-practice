#include <bits/stdc++.h>
using namespace std;
#include <cmath>

int main() {
    long long n, i;
    cin >> n >> i;
    long long curr_digit_num, diff;
    // first step is to find what digit range we are in
    // and how many into that we are
    curr_digit_num = to_string(n).size();
    while (true) {
        diff = pow(10, curr_digit_num) - n;
        diff = diff * curr_digit_num;
        if (i - diff <= 0) break;
        n = pow(10, curr_digit_num);
        i -= diff;
        curr_digit_num++;
    }
    int remainder;
    long long whole_num = i/curr_digit_num;
    if (i % curr_digit_num == 0) {
        whole_num--;
        remainder = curr_digit_num;
    } else {
        remainder = i % curr_digit_num;
    }
    whole_num = n + whole_num;
    cout << (to_string(whole_num))[remainder-1];
}
#include <bits/stdc++.h>
using namespace std;
#include <cmath>

int part_a() {
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
    return 0;
}

int part_c() {
    long long total = 0;
    for (int digit=1; digit<9; digit++) {
        total += ((pow(10, digit) - pow(10, digit-1))) * digit;
    }
    total += (long long)(98765432 * 9);
    total += 2;
    cout << "start: " << total << "\n"; 
    cout << "end: " << total + 8 << "\n";
    return 0;
}


int main() {
    part_c();
}
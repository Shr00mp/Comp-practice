#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string s) {
    for (int i=0; i<s.size()/2; i++) {
        if (s[i] != s[s.size()-i-1]) {
            return false;
        }
    }
    return true;
}

int part_a() {
    int sum; cin >> sum;
    int num1, num2, num3;
    if (is_palindrome(to_string(sum))) {
        cout << sum;
        return 0;
    }
    // check if 2
    for (num1=0; num1<sum; num1++) {
        if (!is_palindrome(to_string(num1))) 
            continue;
        num2 = sum - num1;
        if (is_palindrome(to_string(num2))) {
            cout << num1 << " " << num2;
            return 0;
        }
    }
    // check if 3
    for (num1=0; num1<sum; num1++) {
        if (!is_palindrome(to_string(num1))) 
            continue;
        for (num2=0; num2<sum-num1; num2++) {
            if (!is_palindrome(to_string(num2)))
                continue;
            num3 = sum - num1 - num2;
            if (is_palindrome(to_string(num3))) {
                cout << num1 << " " << num2 << " " << num3;
                return 0;
            }
        }
    }
    return 0;
}

int part_b() {
    // contains overlaps
    int sum = 54;
    int num1, num2, num3;
    if (is_palindrome(to_string(sum))) {
        cout << sum << "\n";
    }
    // check if 2
    for (num1=0; num1<sum; num1++) {
        if (!is_palindrome(to_string(num1))) 
            continue;
        num2 = sum - num1;
        if (is_palindrome(to_string(num2))) {
            cout << num1 << " " << num2 << "\n";
        }
    }
    // check if 3
    for (num1=0; num1<sum; num1++) {
        if (!is_palindrome(to_string(num1))) 
            continue;
        for (num2=0; num2<sum-num1; num2++) {
            if (!is_palindrome(to_string(num2)))
                continue;
            num3 = sum - num1 - num2;
            if (is_palindrome(to_string(num3))) {
                cout << num1 << " " << num2 << " " << num3 << "\n";
            }
        }
    }
    return 0;
}

bool requires_three(int sum) {
    int num1, num2, num3;
    // checks if 1
    if (is_palindrome(to_string(sum))) {
        return false;
    }
    // check if 2
    for (num1=0; num1<sum; num1++) {
        if (!is_palindrome(to_string(num1))) 
            continue;
        num2 = sum - num1;
        if (is_palindrome(to_string(num2))) {
            return false;
        }
    }
    return true; // all numbers can
}

int part_c() {
    int count = 0;
    for (int i=1; i<1000000; i++) {
        if (requires_three(i)) 
            count++;
    }
    return count;
}

int main() {
    cout << part_c();
}

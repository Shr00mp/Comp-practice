#include <bits/stdc++.h>
using namespace std;

void part_a() {
    string encrypted;
    cin >> encrypted;
    string original = encrypted;
    char curr, prev, new_c;
    int curr_num, prev_num, new_num;
    for (int i=1; i<encrypted.size(); i++) {
        prev = encrypted[i-1]; curr = encrypted[i];
        prev_num = (int) prev - 64; 
        curr_num = (int) curr - 64;

        if (curr_num <= prev_num) curr_num += 26;
        new_num = curr_num - prev_num;
        new_c = (char) (new_num + 64);

        original[i] = new_c;
    }
    
    cout << original;
}

int main() {
}

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

void part_b() {
    // ZZZZZ
}

void part_c() {
    string encrypted = "OLYMPIAD";
    string original = encrypted;
    char curr, prev, new_c;
    int curr_num, prev_num, new_num;
    int count = 0;
    while (true) {
        encrypted = original;
        for (int i=1; i<encrypted.size(); i++) {
            prev = encrypted[i-1]; curr = encrypted[i];
            prev_num = (int) prev - 64; 
            curr_num = (int) curr - 64;

            if (curr_num <= prev_num) curr_num += 26;
            new_num = curr_num - prev_num;
            new_c = (char) (new_num + 64);

            original[i] = new_c;
        }
        count++;
        if (original == "OLYMPIAD") {
            break;
        }
    }
    cout << count; // 104
}

void part_d() {
    const long long multiplier = 999999999999;
    int count;
    for (int x=0; x<26; x++) {
        for (int y=0; y<26; y++) {
            for (int z=0; z<26; z++) {
                if (((long long) ((multiplier * x) + y)) % 26 == y) {
                    if (((long long) ((multiplier * y) + z)) % 26 == z) {
                        count++;
                    }
                }
            }
        }
    }
    cout << count; // 4394
}

int main() {
    part_d();
}

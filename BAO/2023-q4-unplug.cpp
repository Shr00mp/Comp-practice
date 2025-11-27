#include <bits/stdc++.h>
using namespace std;
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

int get_min_index(vector<int> v) {
    auto it = min_element(v.begin(), v.end());
    return distance(v.begin(), it);
}

int part_a() {
    // For a specific sequence, look at each triplet of consecutive numbers and find smallest num
    // of moves it would take to remove it
    // Remove the triplet that takes the smallest number of moves. Then re-evaluate the 
    // new surrounding triplets, etc.
    long long num_turns = 0;
    
    bool already_unplugged = false;
    vector<int> row;
    string row_s;
    cin >> row_s;
    for (char s: row_s) {
        row.push_back((int) s - '0');
    }

    vector<int> min_vals = vector<int>();
    int a, b, c;
    int first, second, third;
    int min_index;
    for (int i=0; i<row.size()-2; i++) {
        first = row[i]; second = row[i+1]; third = row[i+2];
        a = abs(first - second);
        b = abs(second - third);
        c = abs(first - third);
        a = a == 3 ? 2 : a;
        a = a == 4 ? 1 : a;
        b = b == 3 ? 2 : b;
        b = b == 4 ? 1 : b;
        c = c == 3 ? 2 : c;
        c = c == 4 ? 1 : c;
        min_vals.push_back(min(a+b, min(a+c, b+c)));
    }  
    min_index = get_min_index(min_vals);
    num_turns += min_vals[min_index];
    if (num_turns == 0) {already_unplugged = true;}
    int end;
    end = min(min_index+2, (int) min_vals.size()-1);
    min_vals.erase(min_vals.begin() + min_index,
               min_vals.begin() + end + 1);
    end = min(min_index+2, (int) row.size()-1);
    row.erase(row.begin() + min_index,
               row.begin() + end + 1);
    while (!row.empty()) { 
        if (min_index >= 1) {
            first = row[min_index-1]; second = row[min_index]; third = row[min_index+1];
            a = abs(first - second);
            b = abs(second - third);
            c = abs(first - third);
            a = a == 3 ? 2 : a;
            a = a == 4 ? 1 : a;
            b = b == 3 ? 2 : b;
            b = b == 4 ? 1 : b;
            c = c == 3 ? 2 : c;
            c = c == 4 ? 1 : c;
            min_vals[min_index-1] = min(a+b, min(a+c, b+c));
        } 
        if (min_index >= 2) {
            first = row[min_index-2]; second = row[min_index-1]; third = row[min_index];
            a = abs(first - second);
            b = abs(second - third);
            c = abs(first - third);
            a = a == 3 ? 2 : a;
            a = a == 4 ? 1 : a;
            b = b == 3 ? 2 : b;
            b = b == 4 ? 1 : b;
            c = c == 3 ? 2 : c;
            c = c == 4 ? 1 : c;
            min_vals[min_index-2] = min(a+b, min(a+c, b+c));
        }
        min_index = get_min_index(min_vals);
        if (min_vals[min_index] == 0 and already_unplugged) {
            already_unplugged = false;
            int min_val = 20;
            for (int idx=0; idx<min_vals.size(); idx++) {
                if (min_vals[idx] < min_val && min_vals[idx] != 0) {
                    min_index = idx;
                    min_val = min_vals[idx];
                }
            }
        }
        num_turns += min_vals[min_index];
        end = min(min_index+2, (int) min_vals.size()-1);
        min_vals.erase(min_vals.begin() + min_index,
                min_vals.begin() + end + 1);
        end = min(min_index+2, (int) row.size()-1);
        row.erase(row.begin() + min_index,
                row.begin() + end + 1);

    }
    return num_turns;
}

int main() {
    long long num_turns = part_a();
    cout << num_turns;
}
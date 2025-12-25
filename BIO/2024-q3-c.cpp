#include <bits/stdc++.h>
using namespace std;

long long location = 0;
long long score = 0;

void dfs(string curr_s, long long curr_score) {
    // base cases
    if (curr_score > score) {
        return;
    } else if (curr_score == score) {
        location++;
        return;
    }
    char curr_char;
    for (int c=65; c<=90; c++) {
        curr_char = (char) c;
        if (curr_s.size() > 0) {
            if (curr_s.back() == curr_char) continue;
        }
        dfs(curr_s + curr_char, curr_score + c-64);
    }
}

void part_b() {
    score = 54;
    dfs("", 0);
}

int main() {
    part_b();
    cout << location;
}

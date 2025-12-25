#include <bits/stdc++.h>
using namespace std;

long long location = 0;
long long score = 0;
string s;

bool dfs(string curr_s, long long curr_score) {
    // if we have found the string
    if (curr_s == s) {
        location++;
        return true;
    }
    // base cases
    if (curr_score > score) {
        return false;
    } else if (curr_score == score) {
        location++;
        return false;
    }
    char curr_char;
    for (int c=65; c<90; c++) {
        curr_char = (char) c;
        if (curr_s.size() > 0) {
            if (curr_s.back() == curr_char) continue;
        }
        if (dfs(curr_s + curr_char, curr_score + c-64)) {
            return true;
        }
    }
    return false;
}

void part_a() {
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        score += (int) s[i] - 64;
    }
    dfs("", 0);
}

int main() {
    part_a();
    cout << location;
}

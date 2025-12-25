#include <bits/stdc++.h>
using namespace std;

long long score = 0;
vector<int> possible;

void dfs(string curr_s, long long curr_score) {
    // base cases
    if (curr_score > score) {
        return;
    } else if (curr_score == score) {
        possible.push_back(curr_s.size());
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

int part_d() {
    score = 54;
    dfs("", 0);

    long long count;
    long long max_diff;
    long long diff;
    for (int i=0; i<possible.size()-1; i++) {
        diff = possible[i+1] - possible[i];
        if (diff > max_diff) {
            max_diff = diff;
        } else if (diff == max_diff) {
            count++;
        }
    }
    return max_diff, count;
}

int main() {
    int max_diff, count = part_d();
    cout << "Number of possibilities: " << (long long) possible.size() << "\n";
    cout << "max_diff: " << max_diff << "\n"; 
    cout << "count: " << count << "\n";
}

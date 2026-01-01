#include <bits/stdc++.h>
using namespace std;

string do_swap(string s, int j) {
    // prefix is 0 to i inclusive
    string ns = s;
    char curr_char;
    for (int i=0; i<=j; i++) {
        curr_char = s[i];
        ns[j-i] = curr_char;
    }
    return ns;
}

int main() {
    int N; cin>>N;
    string og; cin >> og;
    // will only swap parity of position if prefix is even length 
    // algorithm:
    // iterate from start to finish, and keep track of number wrong and right
    // if the diff is at any point larger than the max (starts being 0)
    // then, that section should be stored as the prefix
    // but make sure you are swapping an even-length prefix
    // if need be, add the next letter to prefix. but only if it's an H
    // if it's a G, then check that the next time around 
    // do this until there is no more need to swap 
    
    int num_correct = 0;
    int num_incorrect = 0;
    int num_swaps = 0;
    int max_diff = 0;
    int j = 0; // j is the index, not the postion
    while (true) {
        for (int i=0; i<og.size(); i++) {
            // remember that positioning starts from 1, not 0.
            // so actual position is i+1
            if (og[i] == 'G') {
                if ((i+1) % 2 == 0) num_correct++;
                else num_incorrect++;
            }
            if ((i+1) % 2 == 0) {
                if (num_incorrect - num_correct > max_diff) {
                    max_diff = num_incorrect - num_correct;
                    j = i; 
                }
            }
        }
        if (j == 0) {
            // no swaps
            break;
        } else {
            og = do_swap(og, j);
            num_swaps++;
        }
        num_correct = 0; num_incorrect=0; max_diff=0; j=0;        
    }

    cout << num_swaps;
    return 0;
}

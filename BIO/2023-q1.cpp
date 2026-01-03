#include <bits/stdc++.h>
using namespace std;

vector<int> fib_sequence;

void generate_fib(int n) {
    int first = 1;
    int second = 2;
    int third = first + second;
    fib_sequence.push_back(first); 
    fib_sequence.push_back(second);
    while (third <= n) {
        fib_sequence.push_back(third);
        first = second; second = third;
        third = first + second;
    }
    return;
}

int main() {
    // brute force 
    // suppose that we want to include two adjacent numbers
    // our code will always instead just choose the number they sum to 
    // so we don't need to consider this 
    int n; cin >> n;
    generate_fib(n);

    int last_index = fib_sequence.size();
    int curr_num; vector<int> result;
    while (n > 0) {
        for (int i=last_index-1; i>=0; i--) {
            if (fib_sequence[i] <= n) {
                curr_num = fib_sequence[i];
                result.push_back(curr_num);
                last_index = i;
                break;
            }
        }
        n -= curr_num;
    }

    for (int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}

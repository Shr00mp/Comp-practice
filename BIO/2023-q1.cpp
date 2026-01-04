#include <bits/stdc++.h>
using namespace std;

vector<long long> fib_sequence;

void generate_fib(long long n) {
    long long first = 1;
    long long second = 2;
    long long third = first + second;
    fib_sequence.push_back(first); 
    fib_sequence.push_back(second);
    while (third <= n) {
        fib_sequence.push_back(third);
        first = second; second = third;
        third = first + second;
    }
    return;
}

void part_a() {
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
    return;
}

void part_b() {
    generate_fib(1000000);
    cout << fib_sequence.back(); // 832040
    return;
}

void part_c() {
    generate_fib(53316291173);
    cout << (long long) fib_sequence.size(); // 52
    // choose 3 numbers, but no 2 can be next to each other 
    // and must add to less than 1,000,000 
    return;
}

int main() {
}

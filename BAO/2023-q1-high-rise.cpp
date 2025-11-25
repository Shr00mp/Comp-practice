#include <bits/stdc++.h>
using namespace std;
#include <cmath>

vector<long long> part_a() {
    vector<long long> T(499, 0);
    T[1] = 2; T[2] = 2;
    int e = 23;
    long long n;
    // f is in the range 1 to 60 
    for (int f=3; f<=498; f++) {
        n = e*f;
        T[f] = 4*log10(n) + T[f-1] + ceil((7.0/20000.0) * T[f-2]);
    }
    cout << "Value on the 33rd floor: " << T[33] << "\n"; // 334
    cout << "Value on the 498th floor: " << T[498]; // 7869
    vector<long long> all_possible_values(T.begin(), T.begin()+61);
    return all_possible_values;
} 

void part_b() {
    int n = 1;
    int m = -3;
    // proof written on paper
}

// void part_d(vector<int> T_values) {
//     int F; cin>>F;
//     // calculate number of beams + first 4 digits of number of wires
//     int T = T_values[F];
//     long long num_support_beams = pow(2, F+1) -3;
//     long long num_wires = pow(F, 2) + (F*(F-1)*(pow(2, F+1) -3));
//     string num_wires_s = to_string(num_wires);
//     cout << "Number of beams: " << num_support_beams << "\n";
//     cout << "Number of wires required: ";
//     for (int i=0; i<4; i++) {
//         cout << num_wires_s.at(i);
//     }
// }

long long get_wires_for_f_floor(int F, long long s_f, int t) {
    long long num_wires = 0;
    vector<long long> W_values(F+1);
    W_values[1] = F + s_f;
    num_wires += W_values[1];
    for (int k=2; k<=F; k++) {
        W_values[k] = W_values[k-1] + s_f;
        num_wires += W_values[k];
    }
    num_wires += t;
    return num_wires;
}

void part_d(vector<long long> T_values) {
    int F; cin>>F;
    // calculate number of beams + first 4 digits of number of wires
    int T = T_values[F];
    vector<long long> S_values(F+1);
    vector<long long> W_values(F+1);
    S_values[1] = 1; S_values[2] = 5;
    long long num_beams = 6;
    for (int f=3; f<=F; f++) {
        S_values[f] = S_values[f-1] + pow(2, f);
        num_beams += S_values[f];
    }

    long long num_wires = 0;
    long long s_f, t;
    for (int f=1; f<=F; f++) {
        s_f = S_values[f];
        t = T_values[f];
        num_wires += get_wires_for_f_floor(f, s_f, t);
    }

    string num_wires_s = to_string(num_wires);
    cout << "Number of beams: " << num_beams << "\n";
    cout << "Number of wires: ";
    for (int i=0; i<4; i++) {
        cout << num_wires_s.at(i);
    }
}

bool is_prime(int n) {
    for (int i=2; i<floor(sqrt(n)); i++) {
        if (n % i == 0) {return false;}
    }
    return true;
}

long long part_f() {
    // (i)
    long long count = 1;
    string prev_s;
    long long previous;
    previous = 5; // this is S(2)
    for (long long f=3; f<=pow(10, 12); f++) {
        previous = ((previous+3) *2) - 3;
        prev_s = to_string(previous);
        if (prev_s.size() <= 3) {
            if (is_prime(previous)) {count++;}
        } else {
            prev_s = prev_s.substr(prev_s.size()-3, 3);
            if (is_prime(stoi(prev_s))) {count++;};
        }
    }
    return count;
}

int main() {
    vector<long long> T_values = part_a();
    cout << "\n";
    part_d(T_values);
    // long long count = part_f();
    // cout << "Count: " << count << "\n";
}

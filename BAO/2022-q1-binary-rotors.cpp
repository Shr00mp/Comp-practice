#include <bits/stdc++.h>
using namespace std;
#include <cmath>
#include <algorithm>

int XOR(int a, int b) {
    if (a==1 && b==0) {
        return 1;
    } else if (a==0 && b==1) {
        return 1;
    } else {
        return 0;
    }
}

string do_r_rotations(string shift, int r) {
    // if (r>=0) {
    //     // Positive roation -> first digit moved to the end
    //     for (int i=0; i<r; i++) {
    //         shift = shift.substr(1, shift.length() - 1) + shift[0];
    //     }
    // } else if (r < 0) {
    //     // Negative rotation -> last digit moved to front
    //     for (int i=0; i>r; i--) {
    //         shift = shift[shift.length()-1] + shift.substr(0, shift.length()-1);
    //     }
    // }
    // return shift;
    int L = shift.length();
    string section1, section2;
    if (r >= 0) {
        // Positive rotation -> first digit moved to the end
        // e.g. r=3, first 3 digits moved to end
        r = r % L;
        section1 = shift.substr(0, r); 
        section2 = shift.substr(r, L-r);
        shift = section2 + section1;
    } else if (r < 0) {
        // Negative rotation -> last digit moved to front
        // e.g. r=3, last 3 digits moved to front
        r = r % L;
        r = -1 * r;
        section1 = shift.substr(0, L-r);
        section2 = shift.substr(L-r, r);
        shift = section2 + section1;
    }
    return shift;
}

string part_a() {
    string shift, check;
    int r;
    char s0, s1, ci;
    int first_xor;
    cin >> shift >> check >> r;
    for (int i=0; i<shift.length(); i++) {
        shift = do_r_rotations(shift, r);
        s0 = shift[0]; s1 = shift[shift.length()-1];
        ci = check[i];
        first_xor = XOR(s0 - '0', s1 - '0');
        check[i] = XOR(first_xor, ci - '0') + '0';
    }
    return check;
}

int main() {
    string check = part_a();
    cout << check;
}
 
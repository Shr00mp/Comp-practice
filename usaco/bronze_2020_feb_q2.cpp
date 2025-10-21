#include <bits/stdc++.h>
using namespace std;
#include <cmath>

int main() {  
    freopen("breedflip.in", "r", stdin);
	freopen("breedflip.out", "w", stdout);

    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int swap_number = 0;
    bool equal = false;

    if (a[0] == b[0]) {
        equal = true;
    }
    else {
        equal = false;
    }
    for (int i=1; i < a.length(); i++) {
        if (a[i] == b[i]) {
            if (equal == false) {
                swap_number += 1;
                equal = true;
            }
            else {
                continue;
            }
        }
        else if (a[i] != b[i]) {
            if (equal == false) {
                continue;
            }
            else if (equal == true) {
                equal = false;
            }
        }
    }
    
    cout << swap_number;
}



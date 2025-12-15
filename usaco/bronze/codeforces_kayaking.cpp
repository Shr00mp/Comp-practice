#include <bits/stdc++.h>
using namespace std;
#include <cmath>

int get_total_instability(vector<int> &weights) {
    int instability = 0;
    for (int i=0; i<weights.size()-1; i+=2) {
        instability += weights[i+1] - weights[i];
    }
    return instability;
}

int main() {
    int n; cin >> n;
    vector<int> weights = vector<int>(2*n);
    for (int i=0; i<2*n; i++) {
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end()); // ascending
    
    int min_instability = INT_MAX;
    int instability;
    vector<int> new_weights;
    for (int i=0; i<(2*n); i++) {
        for (int j=i+1; j<(2*n); j++) {
            new_weights = weights;
            new_weights.erase(new_weights.begin()+max(i, j));
            new_weights.erase(new_weights.begin()+min(i, j));
            instability = get_total_instability(new_weights);
            if (instability < min_instability) {min_instability = instability;}
        }
    }
    cout << min_instability;
}

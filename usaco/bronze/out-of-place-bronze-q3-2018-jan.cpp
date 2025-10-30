#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> arrangement(n, 0);
    for (int i=0; i<n; i++) {
        cin >> arrangement[i];
    }

    vector<int> sorted_arrangement = arrangement;
    sort(sorted_arrangement.begin(), sorted_arrangement.end());

    
    int count = 0;
    bool first_time = true;
    int start_pos, end_pos;
    for (int i = 0; i<n; i++) {
        if (sorted_arrangement[i] != arrangement[i]) {
            if (first_time) {start_pos = i; first_time=false;}
            else {end_pos = i;}
        }
    }

    for (int j=start_pos; j<=end_pos; j++) {
        if (j==end_pos && arrangement[j] != arrangement[j-1]){
            count++;
        }
        else if (arrangement[j] != arrangement[j+1]) {
            count++;
        }
    }

    cout << count;
}
 
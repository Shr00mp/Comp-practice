#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>

int main() {
    freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);
    
    int n;
    char current;
    cin >> n;
    vector<char> v;
    for (int i=0; i<n; i++) {
        cin >> current;
        v.push_back(current);
    }

    int pointer_1, pointer_2;
    vector<char> current_v;
    vector<char> new_vector;
    vector<vector<char>> all_new_vectors; 
    bool found = true;
    for (int length=1; length<=n; length++) {
        found = true;
        pointer_1 = 0;
        pointer_2 = 0 + length;
        current_v.clear();
        new_vector.clear();
        all_new_vectors.clear();
        current_v.assign(v.begin()+pointer_1, v.begin() + pointer_2);
        all_new_vectors.push_back(current_v);
        while (pointer_2 < n) {
            pointer_1++;
            pointer_2++;
            new_vector.assign(v.begin()+pointer_1, v.begin()+pointer_2);
            for (vector<char> a_v: all_new_vectors) {
                if (a_v == new_vector) {
                    found = false;
                    break;
                }
            }
            if (!found) {
                break;
            }
            else {
                all_new_vectors.push_back(new_vector); 
            }
        }
        if (found) {
            cout << length;
            break;
        }
    }
}

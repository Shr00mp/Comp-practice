#include <bits/stdc++.h>
using namespace std;
#include <cmath>

set<int> poss = {};

void recurse(int level, int curr_barn, int tank1, int tank2, vector<int> barn1_buckets, vector<int> barn2_buckets) {
    // curr_barn starts off as being barn1
    // level starts off as being 0
    if (level==4) {
        poss.insert(tank1);
        return;
    }
    int curr_bucket, n;
    if (curr_barn == 1) {
        n = barn1_buckets.size();
    } else {
        n = barn2_buckets.size();
    }
    for (int i=0; i<n; i++) {
        if (curr_barn == 1) {
            if (barn1_buckets[i] == -1) {continue;}
            curr_bucket = barn1_buckets[i];
            tank2 += curr_bucket;
            tank1 -= curr_bucket;
            barn1_buckets[i] = -1;
            barn2_buckets.push_back(curr_bucket);
            level++;
            recurse(level, 2, tank1, tank2, barn1_buckets, barn2_buckets);
            tank2 -= curr_bucket;
            tank1 += curr_bucket;
            barn1_buckets[i] = curr_bucket;
            barn2_buckets.pop_back();
            level--;
        } else {
            if (barn2_buckets[i] == -1) {continue;}
            curr_bucket = barn2_buckets[i];
            tank1 += curr_bucket;
            tank2 -= curr_bucket;
            barn2_buckets[i] = -1;
            barn1_buckets.push_back(curr_bucket);
            level++;
            recurse(level, 1, tank1, tank2, barn1_buckets, barn2_buckets);
            tank1 -= curr_bucket;
            tank2 += curr_bucket;
            barn2_buckets[i] = curr_bucket;
            barn1_buckets.pop_back();
            level--;
        }
    }
    return;
}

int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    vector<int> barn1_buckets = vector<int>(10);
    vector<int> barn2_buckets = vector<int>(10);
    int tank1 = 1000; int tank2 = 1000;
    for (int i=0; i<10; i++) {
        cin >> barn1_buckets[i];
    } 
    for (int i=0; i<10; i++) {
        cin >> barn2_buckets[i];
    }
    recurse(0, 1, tank1, tank2, barn1_buckets, barn2_buckets);
    cout << poss.size();
}
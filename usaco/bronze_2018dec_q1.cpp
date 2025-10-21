#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("mixmilk.in", "r", stdin);
    array<int, 3> capacity;
    array<int, 3> milk_level;

    for (int i=0; i<3; i++) {
        cin >> capacity[i];
        cin >> milk_level[i];
    }

    int count = 0;
    for (int j=0; j<100; j++) {
        milk_level[(count+1)%3] += milk_level[count%3];
        if (milk_level[(count+1)%3] > capacity[(count+1)%3]) {
            milk_level[count%3] = milk_level[(count+1)%3] - capacity[(count+1)%3];
            milk_level[(count+1)%3] = capacity[(count+1)%3];
        }
        else {
            milk_level[count%3] = 0;
        }
        count += 1;
    }

    freopen("mixmilk.out", "w", stdout);
    for (int x: milk_level) {
        cout << x << endl;
    }
}
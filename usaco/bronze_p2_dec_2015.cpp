#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);

    int N, M; 
    cin >> N >> M;
    vector<int> speed_limits(100, 0);
    vector<int> cow_speeds(100, 0);
    int length, limit; 
    int current_location = 0;
    for (int i=0; i<N; i++) {
        cin >> length >> limit;
        for (int x=current_location; x<current_location+length; x++) {
            speed_limits[x] = limit;
        }
        current_location = current_location + length;
    }
    current_location = 0;
    for (int j=0; j<M; j++) {
        cin >> length >> limit;
        for (int y=current_location; y<current_location+length; y++) {
            cow_speeds[y] = limit;
        }
        current_location = current_location + length;
    }

    int largest_diff = 0;
    int diff = 0;
    for (int pos=0; pos < 100; pos++) {
        diff = cow_speeds[pos] - speed_limits[pos];
        if (diff > 0 && diff > largest_diff) {
            largest_diff = diff;
        }
    }

    cout << largest_diff;
} 
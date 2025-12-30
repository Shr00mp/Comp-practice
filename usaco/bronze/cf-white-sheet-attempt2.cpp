#include <bits/stdc++.h>
using namespace std;

long long get_overlap(long long x1, long long x2, long long x3, long long x4, 
                long long y1, long long y2, long long y3, long long y4) {
    // get the x bit first
    long long x_left = max(x1, x3);
    long long x_right = min(x2, x4);
    long long y_bottom = max(y1, y3);
    long long y_top = min(y2, y4);
    long long x_length = max((long long) 0, x_right - x_left);
    long long y_length = max((long long) 0, y_top - y_bottom);
    return (long long) x_length * y_length;
}

int main() {
    long long x1, x2, x3, x4, x5, x6;
    long long y1, y2, y3, y4, y5, y6;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;
    // PIE solution
    // white & black 1 overlap + white & black 2 overlap
    // - all three overlap
    // if that's equal to the area of the white rectangle, then completely covered 

    long long white_black1_overlap = get_overlap(x1, x2, x3, x4, y1, y2, y3, y4);
    long long white_black2_overlap = get_overlap(x1, x2, x5, x6, y1, y2, y5, y6);
    long long black_black_overlap = get_overlap(x3, x4, x5, x6, y3, y4, y5, y6);
    
    // find overlap of all three
    // first, white and black1
    long long x_left = max(x1, x3);
    long long x_right = min(x2, x4);
    long long y_bottom = max(y1, y3);
    long long y_top = min(y2, y4);
    // then, what's left and black2
    x_left = max(x_left, x5);
    x_right = min(x_right, x6);
    y_bottom = max(y_bottom, y5);
    y_top = min(y_top, y6);
    long long x_length = max((long long) 0, x_right - x_left);
    long long y_length = max((long long) 0, y_top - y_bottom);
    long long all_overlap = x_length * y_length;

    long long overlap = white_black1_overlap + white_black2_overlap - all_overlap;
    long long white_area = (x2 - x1) * (y2 - y1);
    if (overlap == white_area) cout << "NO";
    else cout << "YES";

    return 0;
}

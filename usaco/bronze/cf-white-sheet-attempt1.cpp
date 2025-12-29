#include <bits/stdc++.h>
using namespace std;

int main() {
    int x1, x2, x3, x4, x5, x6;
    int y1, y2, y3, y4, y5, y6;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;
    // if the entire y sheet is covered, the entire y-length 
    // and entire x-length must be covered 

    // x-axis
    int first_x_covered_left = max(x1, x3);
    int first_x_covered_right = min(x2, x4);
    int second_x_covered_left = max(x1, x5);
    int second_x_covered_right = min(x2, x6);
    int final_left_x = min(first_x_covered_left, second_x_covered_left);
    int final_right_x = max(first_x_covered_right, second_x_covered_right);
    if (first_x_covered_right < second_x_covered_left 
    || second_x_covered_right < first_x_covered_left) {
        cout << "YES";
        return 0;
    } else {
        if (final_left_x > x1 || final_right_x < x2) {
            cout << "YES";
            return 0;
        }
    }

    // y-axis
    int first_y_covered_bottom = max(y1, y3);
    int first_y_covered_top = min(y2, y4);
    int second_y_covered_bottom = max(y1, y5);
    int second_y_covered_top = min(y2, y6);
    int final_bottom_y = min(first_y_covered_bottom, second_y_covered_bottom);
    int final_top_y = max(first_y_covered_top, second_y_covered_top);
    if (first_y_covered_top < second_y_covered_bottom 
    || first_y_covered_bottom > second_y_covered_top) {
        cout << "YES";
        return 0;
    } else {
        if (final_top_y < y2 || final_bottom_y > y1) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}

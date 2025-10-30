#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

    int l_x1, l_y1, l_x2, l_y2;
    int f_x1, f_y1, f_x2, f_y2;
    cin >> l_x1 >> l_y1 >> l_x2 >> l_y2;
    cin >> f_x1 >> f_y1 >> f_x2 >> f_y2;

    int lawn_width, lawn_height;
    lawn_width = l_x2 - l_x1;
    lawn_height = l_y2 - l_y1; 

    int width_overlap, height_overlap;
    width_overlap = max(0, min(l_x2, f_x2) - max(l_x1, f_x1));
    height_overlap = max(0, min(l_y2, f_y2) - max(l_y1, f_y1));

    if (width_overlap == 0 || height_overlap == 0) {
        cout << lawn_width * lawn_height;
    }
    // both smaller
    else if (width_overlap < lawn_width && height_overlap < lawn_height) {
        cout << lawn_width * lawn_height;
    }
    // both bigger or equal to 
    else if (width_overlap >= lawn_width && height_overlap >= lawn_height) {
        cout << 0;
    }
    // only width bigger or equal to 
    else if (width_overlap >= lawn_width && height_overlap < lawn_height) {
        if (f_y1 > l_y1 && f_y2 < l_y2) {
            cout << lawn_width * lawn_height;
        }
        else {cout << (lawn_height - height_overlap) * lawn_width;}
    }
    // only height bigger or equal to 
    else if (width_overlap < lawn_width && height_overlap >= lawn_height) {
        if (f_x1 > l_x1 && f_x2 < l_x2) {
            cout << lawn_width * lawn_height;
        }
        else {cout << (lawn_width - width_overlap) * lawn_height;}
    }
}
 
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	int b1_x1, b1_y1, b1_x2, b1_y2;
    int b2_x1, b2_y1, b2_x2, b2_y2;
    int t_x1, t_y1, t_x2, t_y2;
    cin >> b1_x1 >> b1_y1 >> b1_x2 >> b1_y2;
    cin >> b2_x1 >> b2_y1 >> b2_x2 >> b2_y2;
    cin >> t_x1 >> t_y1 >> t_x2 >> t_y2;
    int total = 0;

    int b1_area = (b1_x2 - b1_x1) * (b1_y2 - b1_y1);
    int b2_area = (b2_x2 - b2_x1) * (b2_y2 - b2_y1);

    int b1_overlap_x = max(min(t_x2, b1_x2) - max(t_x1, b1_x1), 0);
    int b1_overlap_y = max(min(t_y2, b1_y2) - max(t_y1, b1_y1), 0);
    total += b1_area - (b1_overlap_x * b1_overlap_y);

    int b2_overlap_x = max(min(t_x2, b2_x2) - max(t_x1, b2_x1), 0);
    int b2_overlap_y = max(min(t_y2, b2_y2) - max(t_y1, b2_y1), 0);
    total += b2_area - (b2_overlap_x * b2_overlap_y);

    cout << total;
}

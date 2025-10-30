#include <bits/stdc++.h>
using namespace std;

vector<int> prices;
vector<vector<int>> air_conditions;

// For the stalls, if one stall's requirements fulfilled, will be -1
void search(int k, int n, vector<int> stalls, int price) {
    // k --> the index of air_conditioner we are including / exluding
    // n --> total number of air conditioners
    // vector<int> stalls --> situation with the stalls
    
    // Base case not written yet (check if cost of cows reached)
    // Either reached the end of conditioners available or it sufficies
    bool final_case_found = true;
    for (int temp: stalls) {
        if (temp != 0) {
            final_case_found = false; 
            break;
        }
    }
    if (final_case_found) {
        prices.push_back(price);
        return;
    }

    if (k==n) {
        return;
    }

    // Exclude k
    search(k+1, n, stalls, price);

    // Include k
    int start_m = air_conditions[k][0] - 1;
    int end_m = air_conditions[k][1] - 1;
    int reduce_m = air_conditions[k][2];
    int price_m = air_conditions[k][3];
    vector<int> new_stalls = stalls;
    for (int s=start_m; s<=end_m; s++) {
        new_stalls[s] = max(0, new_stalls[s] - reduce_m);
    }
    search(k+1, n, new_stalls, price+price_m);
    // Creating a temporary vector each time so need to backtrack here
}

int main() {
    int N, M;
    int start, end, cost;
    cin >> N >> M;
    air_conditions.resize(M);
    vector<int> c(100, 0);
    for (int n=0; n<N; n++) {
        cin >> start >> end >> cost;
        for (int i=start; i<=end; i++) {
            c[i-1] = cost;
        }
    }
    int reduce, money;
    for (int m=0; m<M; m++) {
        cin >> start >> end >> reduce >> money;
        air_conditions[m] = {start, end, reduce, money};
    }

    // Recursive approach
    // Each air conditioner either include or exclude
    // At any node, check if requirements have been reached
    // Store the price of any one path down the tree

    search(0, M, c, 0);

    cout << *min_element(prices.begin(), prices.end());
}

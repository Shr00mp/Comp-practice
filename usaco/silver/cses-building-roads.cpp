#include <bits/stdc++.h>
using namespace std;
#include <queue>

int main() {
    int num_cities; int num_roads;
    cin >> num_cities; cin >> num_roads;
    int a; int b;
    vector<vector<int>> adj_list(num_cities);
    for (int i=0; i<num_roads; i++) {
        cin >> a; cin >> b;
        adj_list[a-1].push_back(b-1);
        adj_list[b-1].push_back(a-1);
    }

    // Perform a breadth first search
    vector<bool> visited(num_cities, false);
    queue<int> to_visit;
    bool pass_check;
    int curr_node;
    int k = -1;
    vector<vector<int>> new_roads;
    while (true) {
        pass_check = true;
        for (int i=0; i<visited.size(); i++) {
            if (!visited[i]) {
                pass_check = false;
                to_visit.push(i);
                visited[i] = true;
                break;
            }
        }
        if (pass_check) {break;}
        if (k > -1) {
            new_roads.push_back({curr_node+1, to_visit.front()+1});
        }
        while (!to_visit.empty()) {
            curr_node = to_visit.front();
            to_visit.pop();
            for (int city: adj_list[curr_node]) {
                if (!visited[city]) {
                    visited[city] = true;
                    to_visit.push(city);
                }
            }
        }
        k++;
    }

    cout << k << "\n";
    for (vector<int> new_road: new_roads) {
        cout << new_road[0] << " " << new_road[1] << "\n";
    }
}

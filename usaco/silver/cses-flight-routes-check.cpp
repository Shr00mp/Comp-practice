#include <bits/stdc++.h>
using namespace std;
#include <queue>
#include <stack>

vector<vector<int>> adj_list;
vector<bool> visited;
vector<int> cannot_reach(2);
vector<bool> can_reach_all;

void dfs(int curr_node, int n, int start_node) {
    if (can_reach_all[start_node]) {return;}
    for (int neighbour: adj_list[curr_node]) {
        if (!visited[neighbour]) {
            visited[neighbour] = true;
            if (can_reach_all[curr_node]) {
                can_reach_all[start_node] = true;
                return;
            }
            dfs(neighbour, n, start_node);
        }
    }
}

bool check_connections_for(int start_node, int n) {
    bool can_visit;
    visited = vector<bool>(n, false);
    visited[start_node] = true;
    dfs(start_node, n, start_node);
    if (can_reach_all[start_node]) {return true;}
    for (int city=0; city < n; city++) {
        if (!visited[city]) {
            can_visit = false; 
            cannot_reach[0] = start_node;
            cannot_reach[1] = city;
            break;
        } else {can_visit = true;}
    }
    return can_visit;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    adj_list = vector<vector<int>>(n);
    vector<vector<int>> parents_list(n);
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        a--; b--;
        adj_list[a].push_back(b);
        parents_list[b].push_back(a); // i.e. b has parent a 
    }

    can_reach_all = vector<bool>(n, false);
    bool can_visit;
    for (int location=0; location<n; location++) {
        if (!can_reach_all[location]) {
            can_visit = check_connections_for(location, n);
            if (!can_visit) {break;}
            else {
                can_reach_all[location] = true;
                for (int parent: parents_list[location]) {
                    can_reach_all[parent] = true;
                }
                // for (int child: adj_list[location]) {
                //     auto it = find(adj_list[child].begin(), adj_list[child].end(), location);
                //     if (it!=adj_list[child].end()) {
                //         can_reach_all[child] = true;
                //     }
                // }
            }
        } else {
            for (int a_parent: parents_list[location]) {
                can_reach_all[a_parent] = true;
            }
            // for (int a_child: adj_list[location]) {
            //     auto it = find(adj_list[a_child].begin(), adj_list[a_child].end(), location);
            //     if (it!=adj_list[a_child].end()) {
            //         can_reach_all[a_child] = true;
            //     }
            // }
        }
    }

    if (can_visit) {cout << "YES";}
    else {
        cout << "NO" << "\n";
        cout << cannot_reach[0]+1 << " " << cannot_reach[1]+1;
    }
}
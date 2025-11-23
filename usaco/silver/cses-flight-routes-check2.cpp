#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<int> disconnected_pair(2);

void dfs(int curr_node, const vector<vector<int>>& adj_list) {
    for (int neighbour: adj_list[curr_node]) {
        if (!visited[neighbour]) {
            visited[neighbour] = true;
            dfs(neighbour, adj_list);
        }
    }
}

bool check_if_connected(const vector<vector<int>>& adj_list, int n) {
    visited.clear();
    visited = vector<bool>(n, false);
    int curr_node = 0;
    visited[curr_node] = true;
    dfs(curr_node, adj_list);
    for (int node=1; node<n; node++) {
        if (!visited[node]) {
            disconnected_pair[0] = 1;
            disconnected_pair[1] = node+1;
            return false;
        }
    }
    return true;
}


int main() {
    int n, m, a, b;
    cin>>n>>m;
    vector<vector<int>> adj_list_one(n);
    vector<vector<int>> adj_list_two(n);
    for (int i=0; i<m; i++) {
        cin>>a>>b;
        a--; b--;
        adj_list_one[a].push_back(b);
        adj_list_two[b].push_back(a);
    }

    // Perform DFS or BFS on both adj lists
    if (!check_if_connected(adj_list_one, n)) {
        cout << "NO" << "\n" << disconnected_pair[0] << " " << disconnected_pair[1];
    } else if (!check_if_connected(adj_list_two, n)) {
        cout << "NO" << "\n" << disconnected_pair[1] << " " << disconnected_pair[0];
    }else {
        cout << "YES";
    }
}

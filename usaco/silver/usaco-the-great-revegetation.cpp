#include <bits/stdc++.h>
using namespace std;
#include <cmath>

// USACO Silver 2019 Feb P3 The Great Revegetation

vector<int> assignments;
bool is_possible = true;
vector<vector<int>> needs_connection;
vector<vector<int>> cannot_connect;

void dfs(int curr_node) {
    if (!is_possible) {return;}
    int curr_assignment = assignments[curr_node];
    for (int s_neighbour: needs_connection[curr_node]) {
        if (assignments[s_neighbour] == 0) {
            assignments[s_neighbour] = curr_assignment;
            dfs(s_neighbour);
        } else if (assignments[s_neighbour] != curr_assignment) {
            is_possible = false;
            return;
        }
    }
    for (int d_neighbour: cannot_connect[curr_node]) {
        if (assignments[d_neighbour] == 0) {
            assignments[d_neighbour] = curr_assignment == 1 ? 2 : 1;
            dfs(d_neighbour);
        } else if (assignments[d_neighbour] == curr_assignment) {
            is_possible = false;
            return;
        }
    }
}


int main() {
    freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);

    // N pastures, M cows
    int N, M, pasture1, pasture2;
    cin >> N >> M;
    char S_D; 
    needs_connection = vector<vector<int>>(N); 
    cannot_connect = vector<vector<int>>(N);
    for (int i=0; i<M; i++) {
        cin >> S_D >> pasture1 >> pasture2;
        if (S_D == 'S') {
            needs_connection[pasture1-1].push_back(pasture2-1);
            needs_connection[pasture2-1].push_back(pasture1-1);
        } else {
            cannot_connect[pasture1-1].push_back(pasture2-1);
            cannot_connect[pasture2-1].push_back(pasture1-1);
        }
    }
    assignments = vector<int>(N, 0);
    // Search through all nodes using a DFS
    // For each node, consider both s and d nodes
    // For each set of fully connected nodes, there are 2 ways 
    // Since answer is in binary, the ans is 10^number of fully connected graphs
    int num_fully_connected_graphs = 0;
    for (int n=0; n<N; n++) {
        if (assignments[n] == 0) {
            num_fully_connected_graphs++;
            assignments[n] = 1;
            dfs(n);
        }
        if (!is_possible) {break;}
    }

    if (!is_possible) {
        cout << 0;
    } else {
        // Need to print as a string since larger numbers can cause floating point errors
        cout << "1";
        for (int i=0; i<num_fully_connected_graphs; i++) {
            cout << "0";
        }
    }
}

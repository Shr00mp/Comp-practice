#include <bits/stdc++.h>
using namespace std;
#include <queue>
#include <stack>

int main() {
    int n, m;
    cin >> n; cin >> m;
    int a, b;
    // n is number of nodes, m is number of edges
    vector<vector<int>> adj_list(n);
    for (int i=0; i<m; i++) {
        cin >> a; cin >> b;
        a--; b--;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    vector<int> team_assignment(n, 0);
    stack<int> to_visit;
    int curr_node, curr_team;
    // perform  a ,BFS
    for (int p=0; p<n; p++) {
        if (team_assignment[p] == 0) {
            team_assignment[p] = 1;
            to_visit = stack<int>(); // clear stack
            to_visit.push(p);
            while (!to_visit.empty()) {
                curr_node = to_visit.top();
                to_visit.pop();
                if (team_assignment[curr_node] == 1) {curr_team = 2;}
                else if (team_assignment[curr_node] == 2) {curr_team = 1;}
                for (int neighbour: adj_list[curr_node]) {
                    if (team_assignment[neighbour] == 0) {
                        team_assignment[neighbour] = curr_team;
                        to_visit.push(neighbour);
                    }
                }
            }
            // while loop condition is not checked until start of each iter
        }
    }

    bool is_impossible = false;
    for (int node=0; node<n; node++) {
        for (int f: adj_list[node]) {
            if (team_assignment[node] == team_assignment[f]) {
                is_impossible = true;
                break;
            }
        }
        if (is_impossible) {break;}
    }

    if (is_impossible) {
        cout << "IMPOSSIBLE";
    } else {
        for (int team: team_assignment) {
            cout << team << " ";
        }
    }
}

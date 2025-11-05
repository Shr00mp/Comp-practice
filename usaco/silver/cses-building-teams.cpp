#include <bits/stdc++.h>
using namespace std;
#include <queue> 

int main() {
    int num_pupils, num_friendships;
    cin >> num_pupils >> num_friendships;
    vector<int> assigned_team(num_pupils, 0);
    vector<vector<int>> friendships_adj_list(num_pupils);
    int a, b;
    for (int m=0; m<num_friendships; m++) {
        cin >> a >> b;
        a--; b--;
        friendships_adj_list[a].push_back(b);
        friendships_adj_list[b].push_back(a);
    }

    // Perform a breadth first search 
    queue<int> to_visit;
    // A node is not visited if its value in assigned_team=0
    bool done = true;
    int curr_team = 1;
    int curr_node;
    bool impossible = false;
    while (true) {
        done = true;
        for (int p=0; p<num_pupils; p++) {
            if (assigned_team[p] == 0) {
                to_visit.push(p);
                assigned_team[p] = 1;
                curr_team = 2;
                done = false;
                break;
            }
        }
        if (done) {break;}
        while (!to_visit.empty()) {
            curr_node = to_visit.front();
            to_visit.pop();
            for (int neighbour: friendships_adj_list[curr_node]) {
                if (assigned_team[neighbour] == 0) {
                    assigned_team[neighbour] = curr_team;
                    to_visit.push(neighbour);
                }
                if (assigned_team[neighbour] != curr_team && assigned_team[neighbour] != 0){
                    impossible = true;
                    break;
                }
            }
            if (curr_team == 1) {curr_team = 2;}
            if (curr_team == 2) {curr_team = 1;}
        }
        if (impossible) {
            cout << "IMPOSSIBLE";
            break;
        }
    }

    for (int team: assigned_team) {
        cout << team << " ";
    }
}


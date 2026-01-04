#include <bits/stdc++.h>
using namespace std;

bool already_visited(set<vector<string>> &visited, vector<string> &curr) {
    if (visited.count(curr)) return true;
    return false;
}

void part_a() {
    vector<string> original;
    string s;
    for (int i=0; i<4; i++) {
        cin >> s; original.push_back(s);
    }

    vector<string> goal;
    for (int i=0; i<4; i++) {
        cin >> s; goal.push_back(s);
    }
    
    
    // conduct a bfs
    queue<tuple<vector<string>, int>> q;
    q.push({original, 0});
    set<vector<string>> visited;
    vector<string> current; vector<string> neighbour;
    int level;
    if (original == goal) {
        level=-1;
        goto end;
    }
    while (!q.empty()) {    
        current = get<0>(q.front());
        level = get<1>(q.front());
        q.pop();
        visited.insert(current);
        // generate next combinations
        // by moving top of i to top of j
        for (int moving=0; moving<4; moving++) {
            if (current[moving] == "0") continue;
            for (int to=0; to<4; to++) {
                if (to == moving) continue;
                neighbour = current;
                if (neighbour[to] == "0") neighbour[to] = "";
                neighbour[to] += current[moving].back();
                neighbour[moving].pop_back();
                if (neighbour[moving] == "") neighbour[moving] = "0";
                if (neighbour == goal) {goto end;}
                if (!already_visited(visited, neighbour)) q.push({neighbour, level+1}); 
            }
        }
    }
    end:;
    cout << level+1;

    return; 
}

void part_b() {
    // number of arrangements of: 
    // one 0, one two-number stack and the rest singles
    // 4 x 4 x 3 x 3 x 2
    // choose 0 location, choose base, choose top, rearrange 3 blocks
    // = 288
    return;
}

void part_c() {
    // can similuate quite easily with BFS, similar to part a
    return;
}

int main() {
    part_a();
}

#include <bits/stdc++.h>
using namespace std;

int counter = 0;
int i;
int n;
bool found = false;
string final_pref_list;
map<char, int> char_to_i;

void dfs(string final_order, char curr_char, string pref_list) {
    // base cases 
    if (found) return;
    if (pref_list.size() == n) {
        counter++;
        if (counter == i) {
            found = true;
            final_pref_list = pref_list;
            return;
        } else {
            return;
        }
    }
    // have not reached leaf node
    // dfs on all children
    int index_of_curr_char = char_to_i[curr_char];
    vector<string> poss;
    poss.push_back(pref_list + (char) (index_of_curr_char+65));
    for (int i=index_of_curr_char-1; i>=0; i--) {
        if ((int) final_order[i] < (int) curr_char) {
            // means something already there
            // so could have been the preferred spot
            poss.push_back(pref_list + (char) (i+65));
        } else {
            break; // empty spaces that it could have occupied
        }
    }
    for (int i=poss.size()-1; i>=0; i--) {
        dfs(final_order, char (((int) curr_char) + 1), poss[i]);
    }
    return;
}

void part_a() {
    // dfs to get alphabetical order
    // to check for options, check all previous car spaces
    // if occupied, could have been preferred
    // if not occupied, could not have been preferred 

    string final_order; 
    cin >> final_order >> i;
    n = final_order.size();
    // create dictionary of letter : index
    for (int i=0; i<final_order.size(); i++) {
        char_to_i[final_order[i]] = i;
    }

    dfs(final_order, 'a', "");

    cout << final_pref_list;
}

void part_b() {
    // ghcdabefij
}

void part_c() {
    // 16 C 2 = 120 
}

int main() {
    part_a();
}

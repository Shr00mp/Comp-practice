#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>
#include <set>

int main() {
    freopen("notlast.in", "r", stdin);
	freopen("notlast.out", "w", stdout);
    
    int N;
    cin >> N;
    unordered_map<string, int> milk_amounts = {
        {"Bessie", 0},
        {"Elsie", 0},
        {"Daisy", 0},
        {"Gertie", 0},
        {"Annabelle", 0},
        {"Maggie", 0},
        {"Henrietta", 0}
    };
    string curr_cow;
    int milk_amount;
    for (int i=0; i<N; i++) {
        cin >> curr_cow >> milk_amount;
        milk_amounts[curr_cow] += milk_amount;
    }

    set<int> all_milk_amounts;
    for (const auto&x: milk_amounts) {
        all_milk_amounts.insert(x.second);
    }

    int second_lowest;
    int count = 0;
    for (int element: all_milk_amounts) {
        count++;
        if (count == 2) {
            second_lowest = element;
            break;
        }
    } 
    int num_cows = 0;
    string cow;
    for (const auto &y: milk_amounts) {
        if (y.second == second_lowest) {
            num_cows++;
            cow = y.first;
            if (num_cows > 1) {
                cow = "Tie";
                break;
            }
        }
    }
    if (num_cows == 0) {
        cow = "Tie";
    }

    cout << cow << endl;
}

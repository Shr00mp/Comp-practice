#include <bits/stdc++.h>
using namespace std;
#include <queue>
#include <stack>

int main() {
    int curr = 1;
    int nColor = curr == 1 ? 2 : 1;
    // variable = condition ? value_if_true : value_if_false
    // In line above, curr=1 -> nColor=2 and cur=2 -> nColor=1

    while (true) {
        while (true){
            while (true) {
                if (curr == 1) {goto end;}
            }
        }
    }
    end:;
    // Able to jump to specific position in code
    // Useful for exiting many nested loops under a condition
}


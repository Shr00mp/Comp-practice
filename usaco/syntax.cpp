#include <bits/stdc++.h>
using namespace std;
#include <queue>
#include <stack>
#include <cmath>

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

    int result = pow(2, 3); // pow(base, exponent)
    // need to write #include <cmath> at the top

    // Sometimes for really large numbers, printing them can result in floating point errors
    // If you cna, try printing the number as a string

    vector<vector<int>> v(5, vector<int>(3, 0)); 
    // initialise a 5x3 2D vector with all values set to 0

    // A common mistake you make is to forget to set some count variable to 0 at start
    // Don't forget to do that!

    // Remember to make values long long!

    // If you scale a shape by e.g. 1/2, it means that their SIDE LENGTH is half of what it was before
}


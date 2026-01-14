#include <bits/stdc++.h>
using namespace std;
#include <iostream>

int main() {
    while (true) {
        goto end;
    }
    end:;

    // maths
    int result = pow(3, 2);
    double z = sqrt(2.5);
    double abs_x = abs(-2.5);     // 2.5
    double ceil_x = ceil(2.96);    // 3
    double floor_x = floor(2.96);  // 2
    double round_x = round(2.96);  // 3
    cout << fixed << setprecision(2) << 9.129387; // print x to fixed 2dp 
    double something = round(100.0 * 5.4341 + 1e-9) / 100.0; // round to 2dp
    log(10);        // natural log ln(10)
    log10(100);     // log base 10 = 2
    log2(8);        // log base 2 = 3

    int x = 2.3;
    sin(x);
    cos(x);
    tan(x);
    asin(x);  // sin^-1 (-90 to 90)
    acos(x);  // cos^-1 (0 to 180)
    atan(x);  // tan^-1 (-90 to 90))
    // Radians <-> Degrees
    double deg = 90.0;
    double rad = deg * M_PI / 180;
    deg = rad * 180 / M_PI;

    // Mod with floats
    double r = fmod(7.5, 2.3); // remainder = 0.6

    // Factorial and Combinatorics
    int n = 3;
    int k = 2;
    int fact = std::tgamma(n+1);    // factorial for n
    double comb = std::tgamma(n+1)/(std::tgamma(k+1)*std::tgamma(n-k+1)); // 3C2 = 1

    int gcd = std::gcd(4, 8);
    int lcm = std::lcm(8, 4);


    // string -> int
    string s1 = "123";
    int x1 = stoi(s1);
    // int -> string
    int x2 = 34;
    string s2 = to_string(x2);

    // Vector operations
    vector<vector<int>> v(5, vector<int>(3, 0)); 
    // initialise a 5x3 2D vector with all values set to 0
    vector<int> v1 = {1, 2, 3, 4}; // initialise with list 
    v1.insert(v1.begin(), 3); // insert at start
    v1.insert(v1.begin()+2, 3); // insert at index 2
    v1.erase(v1.begin()+2); // erase element at index 2
    v1.erase(v1.begin(), v1.begin()+2); // erases first to last, not including last 
    // for above, would erase indexes 0 and 1
    vector<int> v2 = {1, 2};
    sort(v2.begin(), v2.end()); // sort in ascending order
    sort(v2.begin(), v2.end(), greater<int>()); // sort in descending order
    reverse(v2.begin(), v2.end()); 
    bool vector_sorted = is_sorted(v2.begin(), v2.end());

    // String operations
    string s = "abcde";
    s.insert(2, "ABC"); // insert at index 2
    s.erase(s.begin()+2); // erase index 2
    s.erase(s.begin()+2, s.begin()+3); // erases in range, not including last pointer
    // in case above, only erases index 2 
    s.pop_back(); 

    int i;
    i = s.find('a'); // returns index of first occurence
    i = s.find_first_of('a'); // same as above
    i = s.rfind('a'); // returns index of last occurence
    i = s.find_last_of('a'); // same as above

    string part = s.substr(2); // 2 to end
    string part2 = s.substr(2, 5); // 5 chars from index 2
    reverse(s.begin(), s.end()); // reverse a string
    
    transform(s.begin(), s.end(), s.begin(), ::toupper); // convert to upper case
    transform(s.begin(), s.end(), s.begin(), ::tolower); // convert to lower case

    char ch = 'a';
    char upper = toupper(ch);
    char lower = tolower(upper);
    bool is_lowercase = islower(ch);
    bool is_uppercase = isupper(ch);

    set<int> new_set; // asc order -> min to max
    set<int, greater<int>> desc_set; // descending order
    new_set.insert(1);
    new_set.erase(1);
    bool contains_1 = new_set.count(1);
    int n = new_set.size();
    bool empty = new_set.empty();
    for (auto it=new_set.begin(); it!=new_set.end(); ++it) {
        int element = *it;
        // notice the ++it not it++ -> it is faster actually 
    }
    for (int element: new_set) {}
    for (auto it = new_set.rbegin(); it!=new_set.rend(); ++it) {
        int element = *it;
        // iterate through set reversely 
    }
    set<int> my_set = {1, 3, 5, 7};
    auto it1 = my_set.lower_bound(5); // first >= 5
    cout << *it1 << "\n";             // 5
    auto it2 = my_set.upper_bound(5); // first > 5
    cout << *it2 << "\n";             // 7

    tuple<int, string, double> t = {1, "ello", 1.89};
    int first_element = get<0>(t);
    string second_element = get<1>(t);
    get<0>(t) = 6;
    vector<tuple<int, int, int>> v;
    v.push_back({1, 2, 3}); // adding tuples to vectors

}

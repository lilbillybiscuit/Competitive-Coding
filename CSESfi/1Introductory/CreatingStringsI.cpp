using namespace std;

#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <utility>
#include <algorithm>
#include <set>

typedef pair<int, int> pii;
typedef vector <pii> vpii;
typedef vector<int> vi;
typedef long long ll;

int main() {
    string s; cin >> s;
    set<string> strs;
    sort(s.begin(), s.end());
    do {
        strs.insert(s);
    } while (next_permutation(s.begin(),s.begin()+s.length()));

    cout << strs.size() << endl;
    for (auto a : strs) {
        cout << a << endl;
    }
}
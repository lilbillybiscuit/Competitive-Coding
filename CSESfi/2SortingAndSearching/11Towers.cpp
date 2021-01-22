using namespace std;

#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <utility>
#include <algorithm>
#include <cstring>
#include <set>

typedef pair<int, int> pii;
typedef vector <pii> vpii;
typedef vector<int> vi;
typedef long long ll;

int main() {
    int N; cin >> N;
    multiset<int> boxes;
    for (int i = 0; i<N; i++) {
        int a; cin >> a;
        auto it= boxes.upper_bound(a);
        if (it!=boxes.end()) {
            boxes.erase(it);
        }
        boxes.insert(a);
    }
    cout << boxes.size() << endl;
}
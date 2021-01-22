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

int X, N;
struct interval {
    int first, second;
    interval(int a, int b) {
        first=a,second=b;
    }
    bool operator < (const interval& a) const { return first < a.first; }
    bool operator = (const interval& a) const { return first == a.first && second == a.second; }
};
multiset<int> dist;
set<int> inters;
int main() {
    cin >> X >> N;
    inters.insert(0);
    inters.insert(X);
    dist.insert(X);
    for (int i = 0; i <N; i++) {

        int a; cin >> a;

        auto hi=inters.upper_bound(a);
        int right = *hi;
        hi--; int left=*(hi);
        inters.insert(a);
        auto distit=dist.find(right-left);
        dist.erase(distit);
        dist.insert(a-left);
        dist.insert(right-a);
        auto hi1=dist.end(); hi1--;
        cout << *hi1 << endl;
    }
}
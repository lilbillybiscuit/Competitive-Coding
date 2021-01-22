using namespace std;

#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <utility>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>

typedef pair<int, int> pii;
typedef vector <pii> vpii;
typedef vector<int> vi;
typedef long long ll;
int N, K;

int main() {
    cin >>N >> K;
    pii movies[N];
    for (int i = 0; i<N; i++) cin >> movies[i].second >> movies[i].first;
    sort(movies, movies+N);
    multiset<int> multi;
    int ans=0;
    multi.insert(-1);
    for (int i = 0; i<N; i++) {
        int curstart=movies[i].second,curend=movies[i].first;
        auto hi=multi.upper_bound(curstart);
        if (hi==multi.begin()) {
            if (multi.size() < K) {
                multi.insert(curend);
                ans++;
            }
            continue;
        }
        hi--;
        //int lastend=*multi.upper_bound(curstart);
        multi.erase(hi);
        multi.insert(curend);
        ans++;
    }
    cout << ans << endl;
}
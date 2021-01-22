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

typedef pair<int, int> pii;
typedef vector <pii> vpii;
typedef vector<int> vi;
typedef long long ll;


ll N, T, factories[200005];
bool check(ll max) {
    __int128 sum=0;
    for (int i = 0; i < N; i++) {
        sum+=max/factories[i];
    }
    return sum>=T;
}
int main() {
    cin >> N >> T;
    for (int i=0; i<N; i++) {
        cin >> factories[i];
    }
    ll left=0, right=1000000000000000000, ans=0;
    while (left<right) {
        ll mid=(left+right)/2;
        //cout << mid << endl;
        if (check(mid)) {
            ans=mid;
            right=mid;
        } else {
            left=mid+1;
        }
    }
    cout << right << endl;
}
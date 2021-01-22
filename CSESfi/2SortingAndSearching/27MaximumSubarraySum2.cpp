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
ll N, A, B, nums[200005];
int main() {
    cin >> N >> A >> B;
    ll prefix[N+1];
    prefix[0] =0;
    for (int i=0; i<N; i++) {
        cin >> nums[i];
        prefix[i+1]=prefix[i]+nums[i];
    }
    multiset<ll> multi;
    ll ans=LLONG_MIN;
    multi.insert(0);
    int j=0;
    for (int i=A; i<=N; i++) {
        ll minimum=*multi.begin();
        ans=max(ans, prefix[i]-minimum);
        //while (i-j>=A) {
            multi.insert(prefix[i-A+1]);
        //    j++;
        //}
        if (i>=B) {
            multi.erase(multi.find(prefix[i-B]));
        }
    }
    cout << ans << endl;
}
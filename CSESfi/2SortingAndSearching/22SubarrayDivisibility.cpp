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

int main() {
    int N; cin >> N;
    int nums[N], prefix[N+1]; prefix[0] =0;
    int count[N];
    memset(count, 0, sizeof(count));
    count[0]++;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        prefix[i+1]=(prefix[i]+nums[i])%N;
        if (prefix[i+1]<0) prefix[i+1]+=N;
        count[prefix[i+1]]++;
    }
    ll ans=0;
    for (int i =0; i < N; i++) {
        ll num=count[i];
        if (num<2) continue;
        ans+=(num*(num-1))/2;
    }
    cout << ans << endl;


}
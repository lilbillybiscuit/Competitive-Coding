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
ll N, K, nums[200005];
bool check(ll maxi) {
    ll cur=0, count=0;
    for (int i = 0; i <N; i++) {
        cur+=nums[i];
        if (nums[i] > maxi) return false;
        if (cur > maxi) {
            cur=nums[i];
            count++;
        }
    }
    return count < K;
}
int main() {
    cin >> N >> K; for (int i = 0; i < N; i++) cin >> nums[i];
    ll left=0, right=LLONG_MAX;
    int hi=1;
    while (left<right) {
        ll mid=(left+right)/2;
        if (check(mid)) {
            right=mid;
        } else {
            left=mid+(ll)1;
        }
    }
    cout << right << endl;
}
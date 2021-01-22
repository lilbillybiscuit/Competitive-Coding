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
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
typedef pair<int, int> pii;
typedef vector <pii> vpii;
typedef vector<int> vi;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> policymultiset;
#define setfind(a) find_by_order(a)
#define keypos(a) order_of_key(a)
policymultiset multi;
int N, nums[200005], K;
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i <K; i++) {
        multi.insert(nums[i]);
    }
    ll cur=0, curmid=*multi.setfind((K + 1) / 2 - 1);
    for (int i = 0; i < K; i++) {
        cur+=abs(nums[i] - curmid);
    }
    cout << cur << " ";
    for (int i=K;i<N;i++) {
        multi.erase(multi.setfind(multi.keypos(nums[i-K])));
        multi.insert(nums[i]);
        cur-=abs(nums[i-K] - curmid);
        ll newmid=*multi.setfind((K+1) / 2 - 1);
        cur+=abs(nums[i] - newmid);
        if (K%2==0) {
            cur+=(curmid-newmid);
        }
        cout << cur << " ";
        curmid=newmid;
    }
    cout << endl;
}
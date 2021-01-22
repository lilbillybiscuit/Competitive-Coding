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
    cout << *multi.setfind((K+1)/2-1) << " ";
    for (int i=K;i<N;i++) {
        multi.insert(nums[i]);
        multi.erase(multi.setfind(multi.order_of_key(nums[i-K])));
        cout << *multi.setfind((K+1)/2-1) << " ";
    }
    cout << endl;
}
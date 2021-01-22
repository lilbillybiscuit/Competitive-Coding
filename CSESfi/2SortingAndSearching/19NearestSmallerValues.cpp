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
#include <stack>

typedef pair<int, int> pii;
typedef vector <pii> vpii;
typedef vector<int> vi;
typedef long long ll;
int N, nums[200005];
int main() {
    cin >> N; for (int i = 0; i < N; i++) cin >> nums[i];
    stack<pair<int, int>> hi;
    for (int i = 0; i < N; i++) {
        while (!hi.empty()&&hi.top().first>=nums[i]) hi.pop();
        if (hi.empty()) cout << 0 << " ";
        else cout << hi.top().second+1 << " ";
        hi.push({nums[i],i});
    }
}
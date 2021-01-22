using namespace std;

#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <utility>
#include <algorithm>
#include <cstring>

typedef pair<int, int> pii;
typedef vector <pii> vpii;
typedef vector<int> vi;
typedef long long ll;

int main() {
    int N; cin >> N; int X; cin >> X;
    pii nums[N];
    for (int i = 0; i < N; i++) {
        cin >> nums[i].first; nums[i].second=i;
    }
    sort(nums,nums+N);
    for (int i = 0; i < N-1; i++) {
        pii need={X-nums[i].first,0};
        auto a = lower_bound(nums+i+1,nums+N,need);
        if (a->first==need.first) {
            cout << nums[i].second+1 <<" " << a->second+1 << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
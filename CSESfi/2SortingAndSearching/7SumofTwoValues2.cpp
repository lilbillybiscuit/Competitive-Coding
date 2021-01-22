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
    int N, X; cin >> N >> X; pii nums[N]; for (int i = 0; i < N; i++) cin >> nums[i].first; for (int i = 0; i < N; i++) nums[i].second=i;
    sort(nums, nums+N);
    int left=0, right=N-1;
    while (left<right) {
        int sum=nums[left].first+nums[right].first;
        if (sum<X) {
            left++;
        } else if (sum>X) {
            right--;
        } else {
            cout << nums[left].second+1 << " " << nums[right].second+1 << endl;
            exit(0);
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
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

int N, X;
pii nums[5005];

bool gettwo(int remain, int index, int index2) {
    int left=index+1,right=N-1;
    while (left<right) {
        int sum=nums[left].first+nums[right].first;
        if (sum<remain) {
            left++;
        } else if (sum>remain) {
            right--;
        } else {
            cout << nums[index].second+1 << " " << nums[index2].second+1<< " " << nums[left].second+1 << " " << nums[right].second+1 << endl;
            exit(0);
            return true;
        }
    }
    return false;
}

int main() {
    cin>>N>>X; for (int i = 0; i < N; i++) {
        cin >> nums[i].first;
        nums[i].second=i;
    }
    sort(nums,nums+N);
    for (int i=0; i<N-3; i++) {
        for (int j=i+1; j<N-2; j++) {
            pii sum2={X-nums[i].first-nums[j].first, nums[i].second};
            gettwo(sum2.first, j,i);
        }

    }
    cout << "IMPOSSIBLE" << endl;
}
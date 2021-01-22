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
    int N; cin >> N; ll nums[N]; for (int i = 0; i<N; i++) cin >> nums[i];
    ll prefix[N+1]; prefix[0]=0; for (int i = 1;i<=N; i++) prefix[i]=prefix[i-1]+nums[i-1];
    ll minprefix[N+1]; minprefix[0]=prefix[0]; for (int i =1; i<=N; i++) minprefix[i]=min(minprefix[i-1],prefix[i-1]);
    ll ans=0;
    for (int i = 1; i<=N; i++) {
        ans=max(ans, prefix[i]-minprefix[i]);
    }
    if (ans==0) {
        ans=INT_MIN;
        for (int i=0; i<N; i++) {
            ans=max(ans, nums[i]);
        }
    }
    cout << ans << endl;
}
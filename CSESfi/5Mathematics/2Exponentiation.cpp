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

ll MOD=1e9+7;

int power(int a, int b) {
    ll dp[100];
    dp[0]=a;
    for (int i=1; i<100; i++) {
        dp[i]=dp[i-1]*dp[i-1]%MOD;
    }
    //b: bitmask
    ll ans=1;
    for (int i=0; i<32; i++) {
        if (b&(1<<i)) {
            ans=ans*dp[i]%MOD;
        }
    }
    return ans;
}

int main() {
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        int a, b; cin >> a >> b;
        cout << power(a,b) << endl;
    }
}
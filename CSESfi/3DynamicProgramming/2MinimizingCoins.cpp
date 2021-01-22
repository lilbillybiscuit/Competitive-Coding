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

typedef pair<int, int> pii;
typedef vector <pii> vpii;
typedef vector<int> vi;
typedef long long ll;
int N, X;
int coins[105];
vector<int> dp(1000005,1e9);

int dynamic(int id, int remain) {
    if (id==N) return 0;
    if (dp[remain]!=-1) return dp[remain];
    for (int i=0; i<N; i++) {

    }
}
int main() {
    cin >> N >> X;
    for (int i=0; i<N; i++) {
        cin >> coins[i];
    }
    dp[0]=0;
    for (int i=1; i<=X; i++) {
        for (int coin : coins) {
            if (i>=coin) dp[i]=min(dp[i],dp[i-coin]+1);
        }
    }
    if (dp[X]==1e9) cout << -1 << endl;
    else cout << dp[X] << endl;
}
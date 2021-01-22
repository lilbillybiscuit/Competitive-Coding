using namespace std;

#include <bits/extc++.h>

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef long long ll;
#define debug(x) cout << x << endl;
#define timerstart chrono::high_resolution_clock::time_point MFA83N03MF = chrono::high_resolution_clock::now();
#define timerend cout << ((chrono::duration<double, std::milli>)(chrono::high_resolution_clock::now() - MFA83N03MF)).count() << endl;
int N, X;
int price[1005],pages[1005];
int dp[1005][100005];
int dynamic(int ind, int curprice) {
    if (curprice>=X) {
        return 0;
    }
    if (ind>=N) return 0;
    if (dp[ind][curprice]!=-1) return dp[ind][curprice];
    int ret1=0,ret2=0;
    if (price[ind]<=X-curprice) {
        ret1=dynamic(ind+1, curprice+price[ind])+pages[ind];
    }

    ret2=dynamic(ind+1,curprice);
    return dp[ind][curprice]=max(ret1,ret2);
}

int main() {
    cin >> N >> X;
    memset(dp,0,sizeof(dp));
    for (int i=0; i<N; i++) cin >> price[i];
    for (int i=0; i<N; i++) cin >> pages[i];
    for (int i=1; i<=N; i++) {
        for (int j=0; j<=X; j++) {
            //cout << i << " " << j << endl;
            dp[i][j]=dp[i-1][j];
            if (i<=0) continue;
            int temp=j-price[i-1];
            if (temp>=0) { //Still have money left
                dp[i][j]=max(dp[i][j],dp[i-1][temp]+pages[i-1]);
            }
        }
    }
    cout << dp[N][X] << endl;
}
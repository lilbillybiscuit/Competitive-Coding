using namespace std;

#include <bits/extc++.h>

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef long long ll;
#define debug(x) cout << x << endl;
#define timerstart chrono::high_resolution_clock::time_point MFA83N03MF = chrono::high_resolution_clock::now();
#define timerend cout << ((chrono::duration<double, std::milli>)(chrono::high_resolution_clock::now() - MFA83N03MF)).count() << endl;
int dp[100005][105],N,M,arr[100005];
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    memset(dp,0,sizeof(dp));
    if (arr[0]==0) {
        for (int i=0; i<=M; i++) {
            dp[0][i]=1;
        }
    } else {
        dp[0][arr[0]]=1;
    }

    for (int i=1; i<N; i++) {
        if (arr[i]==0) {
            for (int j=0; j<=M; j++) {
                for (auto hi : {j-1,j,j+1}) {
                    if (hi<1||hi>M) continue;
                    (dp[i][j]+=dp[i-1][hi])%=(int)(1e9+7);
                }
            }
        } else {
            for (auto hi : {arr[i]-1,arr[i], arr[i]+1}) {
                if (hi<1||hi>M) continue;
                (dp[i][arr[i]]+=dp[i-1][hi])%=(int)(1e9+7);
            }
        }
    }

    /*for (int i=1; i<N; i++) {
        if (arr[i]!=0) {
            dp[i][arr[i]]=((arr[i]>0?dp[i-1][arr[i]-1]:0)+dp[i-1][arr[i]]+dp[i-1][arr[i]+1])%(int)(1e9+7);
        } else {
            int elem=arr[i-1];
            dp[i][elem]=((elem<=0?0:dp[i-1][elem-1])+dp[i-1][elem]+dp[i-1][elem+1])%(int)(1e9+7);
            elem=arr[i-1]-1;
            dp[i][elem]=((elem<=0?0:dp[i-1][elem-1])+(elem<0?0:dp[i-1][elem])+dp[i-1][elem+1])%(int)(1e9+7);
            elem=arr[i-1]+1;
            dp[i][elem]=(dp[i-1][elem-1]+dp[i-1][elem]+dp[i-1][elem+1])%(int)(1e9+7);
        }
    }*/
    int ans=0;
    for (int i=1;i<=M;i++) {
        ans+=dp[N-1][i];
        ans%=(int)(1e9+7);
    }
    cout << ans << endl;
}
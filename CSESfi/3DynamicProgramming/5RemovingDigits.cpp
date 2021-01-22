using namespace std;

#include <bits/extc++.h>

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef long long ll;
#define debug(x) cout << x << endl;
#define timerstart chrono::high_resolution_clock::time_point MFA83N03MF = chrono::high_resolution_clock::now();
#define timerend cout << ((chrono::duration<double, std::milli>)(chrono::high_resolution_clock::now() - MFA83N03MF)).count() << endl;

int N;
int dp[1000005];
int tens[8]={1,10,100,1000,10000,100000,1000000,10000000};
int getdigit(int num, int ind) {
    return (num/tens[ind])%10;
}

int dynamic(int ind) {
    if (ind<=0) return 0;
    if (dp[ind]!=-1) return dp[ind];
    int ret=INT_MAX;
    for (int i=0; i<8&&tens[i]<ind; i++) {
        ret=min(ret,dynamic(ind-getdigit(ind,i)));
    }
    return dp[ind]=1+ret;

}


int main() {
    cin >> N;
    for (int i=0; i<=N; i++) {
        dp[i]=INT_MAX;
    }
    dp[0]=0;
    for (int i=0; i<=N; i++) {
        for (int j=0; j<8&&tens[j]<=i; j++) {
            if (getdigit(i,j)==0) continue;
            dp[i]=min(dp[i],1+dp[i-getdigit(i,j)]);
        }
    }
    cout << dp[N] << endl;
}
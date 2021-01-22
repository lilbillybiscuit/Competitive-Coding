using namespace std;

#include <bits/extc++.h>

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef long long ll;
#define debug(x) cout << x << endl;
#define timerstart chrono::high_resolution_clock::time_point MFA83N03MF = chrono::high_resolution_clock::now();
#define timerend cout << ((chrono::duration<double, std::milli>)(chrono::high_resolution_clock::now() - MFA83N03MF)).count() << endl;
int N,X;
int coins[105];
int dp[1000005];
int main() {
    cin >>N >> X;
    for (int i=0; i<N; i++) {
        cin >> coins[i];
    }
    dp[0]=1;
    for (int i=0; i<N; i++) {
        for (int j=0; j<=X; j++) {
            if (j>=coins[i]) {
                dp[j]=(dp[j-coins[i]]+dp[j])%(int)(1e9+7);
            }
        }
    }
    cout << dp[X] << endl;
}
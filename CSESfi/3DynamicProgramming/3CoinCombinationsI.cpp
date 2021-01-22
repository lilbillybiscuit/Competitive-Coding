using namespace std;

#include <bits/extc++.h>
#define debug(...) {cerr << #__VA_ARGS__ << "="; de(__VA_ARGS__) }
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef long long ll;
#define timerstart chrono::high_resolution_clock::time_point MFA83N03MF = chrono::high_resolution_clock::now();
#define timerend cout << ((chrono::duration<double, std::milli>)(chrono::high_resolution_clock::now() - MFA83N03MF)).count() << endl;
int coins[105],N,X;
vector<int> dp(1000005,0);
int main() {
    cin >> N >> X;
    for (int i=0; i<N; i++) {
        cin >> coins[i];
    }
    dp[0]=1;
    for (int i=1; i<=X; i++) {
        for (int j=0; j<N; j++) {
            int coin=coins[j];
            if (i>=coin) {
                dp[i]=(dp[i]+dp[i-coin])%(int)(1e9+7);
            }
        }
    }
    cout << dp[X] << endl;
}
using namespace std;

#include <bits/extc++.h>

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef long long ll;
#define debug(x) cout << x << endl;
#define timerstart chrono::high_resolution_clock::time_point MFA83N03MF = chrono::high_resolution_clock::now();
#define timerend cout << ((chrono::duration<double, std::milli>)(chrono::high_resolution_clock::now() - MFA83N03MF)).count() << endl;
char field[1005][1005];
int dp[1005][1005];
int N;
struct State {
    int x, y, dist;
};
int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> field[i][j];
        }
    }
    dp[0][0]=1;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; ++j) {
            if (i>0) dp[i][j]=(dp[i][j]+dp[i-1][j])%(int)(1e9+7);
            if (j>0) dp[i][j]=(dp[i][j]+dp[i][j-1])%(int)(1e9+7);
            if (field[i][j]=='*') dp[i][j]=0;
        }
    }
    cout << dp[N-1][N-1] << endl;
}
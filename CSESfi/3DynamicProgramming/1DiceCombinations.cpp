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
const int MOD=1e9+7;
int dp[1000005];
int main() {
    dp[0]=0;
    for (int i=1; i<=6; i++) {
        dp[i]=1;
        for (int j=1; j<i; j++) {
            dp[i]+=dp[j];
        }
    }
    for (int i = 7; i<1000005; i++) {
        for (int j =i-6; j<i; j++) {
            dp[i]=(dp[j]+dp[i])%(MOD);
        }
    }
    int N; cin >> N; cout << dp[N];

}
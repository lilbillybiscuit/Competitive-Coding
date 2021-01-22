using namespace std;

#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <utility>
#include <algorithm>

typedef pair<int, int> pii;
typedef vector <pii> vpii;
typedef vector<int> vi;
typedef long long ll;

int main() {
    int N;
    cin >> N; const int MOD=1e9+7;
    int ans=1;
    for (int i=0; i<N; i++) {
        ans=ans*2%MOD;
    }
    cout << ans << endl;
}
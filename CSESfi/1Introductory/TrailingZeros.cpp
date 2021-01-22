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
    ll N; cin >> N;
    ll power=5, ans=0;
    while (power<=N) {
        ans+=N/power;
        power*=5;
    }
    cout << ans << endl;
}
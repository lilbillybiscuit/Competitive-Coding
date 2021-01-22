using namespace std;

#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <utility>
#include <algorithm>
#include <cstring>
#include <set>

typedef pair<int, int> pii;
typedef vector <pii> vpii;
typedef vector<int> vi;
typedef long long ll;

int main() {
    int N; cin >> N; int songs[N]; for (int i = 0; i < N; i++) cin >> songs[i];
    set<int> unique;
    ll ans=0, left=0;
    for (int i = 0; i <N; i++) {
        if (unique.find(songs[i]) == unique.end()) {
            unique.insert(songs[i]);
            ans=max(ans, (ll)unique.size());
        } else {
            while (unique.count(songs[i])!=0) {
                unique.erase(songs[left]);
                left++;
            }
            unique.insert(songs[i]);
        }
    }
    cout << ans << endl;
}
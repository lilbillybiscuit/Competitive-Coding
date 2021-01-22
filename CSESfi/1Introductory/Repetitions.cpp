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
    string s; cin >> s;
    int ans=1, count=1;
    for (int i = 1; i < s.length(); i++) {
        if (s[i]==s[i-1]) count++;
        else count=1;
        ans=max(ans, count);
    }
    cout << ans << endl;
}
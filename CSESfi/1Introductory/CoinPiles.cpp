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
    int T; cin >> T;
    for (int i = 0; i <T; i++) {
        int a, b; cin >> a >> b;
        if ((a+b)%3==0&&(a>=b/2)&&(b>=a/2)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
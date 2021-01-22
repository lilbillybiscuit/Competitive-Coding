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
    for (ll i=1; i<=N; i++) {
        cout << i*i*(i*i-1)/2-(i-2)*(i-1)*4 << endl;
    }
}
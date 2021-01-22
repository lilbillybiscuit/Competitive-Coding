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
    int N; cin >> N;
    if (N<=3&&N>1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    for (int i = 2; i <=N; i+=2) {
        cout << i << " ";
    }
    for (int i=1; i <=N; i+=2) {
        cout << i;
        if (i!=N&&i!=N-1) cout << " ";
    }
    cout << endl;
}
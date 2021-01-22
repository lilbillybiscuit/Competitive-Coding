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
    int child[200005];
    int N, X; cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> child[i];
    }
    sort(child, child+N);
    int i=0,j=N-1;
    int cnt=0;
    while (i<=j) {
        if (i==j) {
            cnt++; break;
        }
        if (child[i]+child[j]>X) {
            cnt++; j--;
        } else {
            cnt++; i++;j--;
        }
    }
    cout << cnt << endl;
}
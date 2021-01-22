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
pii rev[200005];
pii normal[200005];
int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        normal[i] ={a,b};
        rev[i] ={b,a};
    }
    sort(normal, normal+N);
    sort(rev, rev+N);
    int count=0, index=-1;
    for (int i = 0; i < N; i++) {
        int start=rev[i].second, end=rev[i].first;
        if (start>=index) {
            index=end;
            count++;
        }
    }
    cout << count << endl;
}
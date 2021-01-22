using namespace std;

#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <utility>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>

typedef pair<int, int> pii;
typedef vector <pii> vpii;
typedef vector<int> vi;
typedef long long ll;
//This one is actually correct
int main() {
    int N; cin >> N;
    ll books[N];
    ll sum=0, max1=0;
    for (int i = 0; i < N; i++) {
        cin >> books[i];
        sum+=books[i];
        max1=max(max1, books[i]);
    }
    ll ret=2*max1;
    if (sum>ret) {
        ret=sum;
    }
    cout << ret << endl;
}
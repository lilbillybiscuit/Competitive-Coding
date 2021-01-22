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
pii customers[200005];
pii events[400005];
int main() {

    int N; cin >>N;
    for (int i = 0; i < N; i++) {
        cin >> customers[i].first >> customers[i].second;
        events[2*i]={customers[i].first, false};
        events[2*i+1]={customers[i].second, true};
    }
    sort(customers, customers+N);
    sort (events,events+2*N);
    int cur=0, ans=0;
    for (int i = 0; i <2*N; i++) {
        auto evt=events[i];
        if (!evt.second) {
            cur++; ans=max(ans,cur);
        } else cur--;
    }
    cout << ans << endl;
}
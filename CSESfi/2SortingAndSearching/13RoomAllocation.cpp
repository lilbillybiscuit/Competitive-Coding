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
struct guest {
    int first, second, third;
    bool operator < (const guest &a) const { return first == a.first?second<a.second:first<a.first; }
};
int main() {
    int N; cin >> N;
    guest guests[N];
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        guests[i]={a,b,i};
    }
    sort(guests, guests+N);
    priority_queue<pii, vector<pii>, greater<pii>> times;
    times.push({guests[0].second,1});
    int ans[N]={0}; ans[guests[0].third]=1;
    int maxrooms=0;
    for (int i=1; i<N; i++) {
        pii lasttime=times.top();
        int cursize=times.size();
        int curstart=guests[i].first, curend=guests[i].second, guestid=guests[i].third;
        if (lasttime.first>=curstart) {
            //allocate new room
            ans[guestid]=cursize+1;
            times.push({curend,cursize+1});

        } else {
            times.pop();
            times.push({curend, lasttime.second});
            ans[guestid]=lasttime.second;
        }
        maxrooms=max(maxrooms,(int)times.size());
    }
    cout << maxrooms << endl;
    for (int i=0; i<N; i++) {
        cout << ans[i]; cout << " ";
    }
    cout << endl;
}
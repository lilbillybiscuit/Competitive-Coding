using namespace std;

#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <utility>
#include <algorithm>
#include <cstring>
#include <map>

typedef pair<int, int> pii;
typedef vector <pii> vpii;
typedef vector<int> vi;
typedef long long ll;
map<int, int> tickets;
int main() {
    int N, M; cin >> N >> M;
    int ticket[N],people[M];
    bool used[N];
    memset(used, 0, sizeof(used));
    for (int i = 0; i<N; i++) {
        cin >> ticket[i];
        tickets[ticket[i]]++;
    }
    for (int i=0; i<M; i++) {
        cin >> people[i];
    }
    sort (ticket, ticket+N);
    for (int person = 0; person<M; person++) {
        //printf("Person: %d, max: %d\n", person, people[person]);
        int maxprice=people[person];
        if (tickets.empty()) {
            cout << -1 << endl; continue;
        }
        auto hi = prev(tickets.upper_bound(maxprice));
        //cout << ans<< endl;
        if ((hi==tickets.begin()&&hi->first>maxprice)||hi->second==0) {
            cout << -1 << endl; continue;
        }
        tickets[hi->first]--;
        if (tickets[hi->first]==0) tickets.erase(hi->first);
        cout << hi->first << endl;
    }
}
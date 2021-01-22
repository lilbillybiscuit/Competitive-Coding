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
#include <bitset>

typedef pair<int, int> pii;
typedef vector <pii> vpii;
typedef vector<int> vi;
typedef long long ll;
struct Node {
    vector<pair<Node*, ll>> connect;
    ll id, value;
};
int N, M;
Node* nodes[100005];
vector<ll> dist;
void Dijkstra(int source, int destination) {//You must traverse the path backwards
    bitset<100005> visited;
    set<pair<ll,ll>> pq;
    dist.assign(N, LLONG_MAX);
    pq.insert({0,source});
    dist[source]=0;

    while (!pq.empty()) {
        ll curdist=pq.begin()->first,curind=pq.begin()->second; pq.erase(*pq.begin());
        visited[curind]=true;
        if (curdist>dist[curind]) continue; //This isn't the shortest path
        for (auto &nxt : nodes[curind]->connect) {
            ll nxtweight=nxt.second, nxtind=nxt.first->id;
            if (!visited[nxtind]&&dist[nxtind]>dist[curind]+nxtweight) {
                pq.insert({dist[curind]+nxtweight, nxtind});
                dist[nxtind]=dist[curind]+nxtweight;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        nodes[i]=new Node(); nodes[i]->id=i;
    }
    for (int i = 0; i <M; i++) {
        int a, b, c; cin >> a >> b >> c; a--,b--;
        nodes[a]->connect.emplace_back(nodes[b],c);
    }
    Dijkstra(0,N-1);
    for (int i=0; i<N; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}
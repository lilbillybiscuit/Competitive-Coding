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
//Basic Dijkstras
struct Node {
    vector<Node*> connect;
    int id, value, prev;
};
int N, M;
Node* nodes[100005];
bool works=false;
int Dijkstras (int source) {
    queue<int> q;
    q.push(source);
    vi visited; visited.assign(N, false);
    nodes[source]->value=0;
    while (!q.empty()) {
        int a=q.front(); q.pop();
        auto cur=nodes[a];
        int dist=cur->value;
        if (a==N-1) {
            works=true;
            return dist;
        }
        for (auto hi : cur->connect) {
            if (!visited[hi->id]) {
                hi->value=dist+1;
                hi->prev=a;
                visited[hi->id]=true;
                q.push(hi->id);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        nodes[i]=new Node(); nodes[i]->id=i;
    }
    for (int i=0; i < M; i++) {
        int a, b; cin >> a >> b; a--,b--;
        nodes[a]->connect.push_back(nodes[b]);
        nodes[b]->connect.push_back(nodes[a]);
    }
    Dijkstras(0);
    if (works) {
        cout << nodes[N-1]->value+1 << endl;
        int cur=N-1;
        vector<int> ans;
        while (cur!=0) {
            ans.push_back(cur);
            cur=nodes[cur]->prev;
        }
        ans.push_back(0);
        reverse(ans.begin(), ans.end());
        for (int i=0; i<ans.size(); i++) {
            cout << ans[i]+1 << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
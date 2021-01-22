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
struct Node {
    vector<Node*> connect;
    int id, visited=false, dist;
};
int N, M;
Node* nodes[100005];
bool startlist=false;
int endnode=-1;
void dfs(int node, int parent, int length) {
    if (nodes[node]->visited&&length>3) {
        startlist=true;
        endnode=node;
        cout << length-nodes[node]->dist+1<< endl;
        cout << node+1 << " ";
        return;
    } else if (nodes[node]->visited) return;
    nodes[node]->visited=true;
    nodes[node]->dist=length;
    for (auto hi : nodes[node]->connect) {
        if (!startlist) {
            if (hi->id!=parent) {
                dfs(hi->id, node, length+1);
            }
        } else break;
    }
    if (startlist) {
        cout << node+1 << " ";
        if (node==endnode) {
            cout << endl;
            exit(0);
        }
    }

}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        nodes[i] = new Node();
        nodes[i]->id=i;
    }
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--,b--;
        nodes[a]->connect.push_back(nodes[b]);
        nodes[b]->connect.push_back(nodes[a]);
    }
    for (int i = 0; i < N; i++) {
        if (!startlist) {
            dfs(i,-1,1);
        } else break;
    }
    if (startlist) {
        cout << endl;
    } else cout << "IMPOSSIBLE" << endl;
}
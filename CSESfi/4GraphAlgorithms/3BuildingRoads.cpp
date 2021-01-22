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

typedef pair<int, int> pii;
typedef vector <pii> vpii;
typedef vector<int> vi;
typedef long long ll;
struct Node {
    vector<Node*> connect;
    int id, visited=false;
};
int N, M;
Node* nodes[100005];
void floodfill(int node) {
    nodes[node]->visited = true;
    for (auto hi : nodes[node]->connect) {
        if (!hi->visited) {
            floodfill(hi->id);
        }
    }
}
int main() {
    cin >> N >> M;
    for (int i = 0; i <N; i++) {
        nodes[i]=new Node();
        nodes[i]->id=i;
    }
    for (int i = 0; i <M; i++) {
        int a, b; cin >> a >> b; a--,b--;
        nodes[a]->connect.push_back(nodes[b]);
        nodes[b]->connect.push_back(nodes[a]);
    }
    int index=0;
    vector<int> ans;
    for (int i=0; i<N; i++) {
        if (!nodes[i]->visited) {
            floodfill(i);
            index++;
            ans.push_back(i);
        }
    }

    cout << index-1 << endl;
    for (int i=0; i<index-1; i++) {
        cout << ans[i]+1 << " " << ans[i+1]+1 << endl;
    }
}
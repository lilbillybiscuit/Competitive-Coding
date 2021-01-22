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
    int id, value;
};
int N, M;
Node* nodes[100005];
void floodfill(int node,int last) {
    if (nodes[node]->value==last) {
        cout << "IMPOSSIBLE" << endl;
        exit(0);
    } else if (nodes[node]->value!=-1) return;
    nodes[node]->value=3-last;
    for (auto a : nodes[node]->connect) {
        if (a->value==nodes[node]->value) {
            cout << "IMPOSSIBLE" << endl;
            exit(0);
        }
        if (a->value==-1) {
            floodfill(a->id, nodes[node]->value);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i=0; i < N; i++) {
        nodes[i]=new Node();
        nodes[i]->id=i;
        nodes[i]->value=-1;
    }
    for (int i=0; i < M; i++) {
        int a, b; cin >> a >> b; a--,b--;
        nodes[a]->connect.push_back(nodes[b]);
        nodes[b]->connect.push_back(nodes[a]);
    }
    for (int i=0; i < N; i++) {
        if (nodes[i]->value==-1) {
            floodfill(i,1);
        }
    }

    for (int i=0; i < N; i++) {
        cout << nodes[i]->value << " ";
    }
    cout << endl;
}
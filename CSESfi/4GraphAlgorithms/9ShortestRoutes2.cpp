using namespace std;

#include <bits/stdc++.h>

typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef vector<pii> vpii;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef set<int> si;
typedef long long ll;
typedef tuple<int, int, int> tiii;
#define sz(arr) sizeof(arr)/sizeof(arr[0])
#define mmset(arr, hi) memset(arr, hi, sizeof(arr))
#define nodegenerate struct Node {vector<Node*> connect; int id, value;};
#define in :

double atan3(double a, double b) {
    double ret = atan2(b, a) * 180.0 / 3.1415926565;
    if (ret < 0) ret = 360.0 + ret;
    return ret;
}

/*************************** END OF TEMPLATE ****************************/
int N, M, Q;
ll adj[505][505];
int main() {
    cin >> N >> M >> Q;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            adj[i][j]=1e16;
        }
    }
    for (int i=0; i<M; i++) {
        ll a, b, c; cin >> a >> b >> c; a--,b--;
        adj[a][b]=min(adj[a][b],c);
        adj[b][a]=min(adj[b][a],c);
    }
    for (int i=0; i<N; i++) {
        adj[i][i]=0;
    }
    for (int k=0; k<N; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
    for (int i=0; i<Q; i++) {
        int a, b; cin >> a >> b; a--,b--;
        if (adj[a][b]==1e16) cout << -1 << endl;
        else cout << adj[a][b] << endl;
    }
}
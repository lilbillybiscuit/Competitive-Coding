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
char field[1005][1005];
int monsterdist[1005][1005], mydist[1005][1005];
int N, M;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
pii track[1005][1005];
char path[1005][1005];
string letters="DRUL";
vector<pii> monsters;
pii start;
struct structure {
    int first, second, dist;
    structure (int a, int b, int c) {
        first=a, second=b, dist=c;
    }
};
void createmonsterdist() {
    queue<structure> q;
    for (auto a : monsters) {
        q.push(structure(a.first, a.second, 0));
        monsterdist[a.first][a.second]=0;
    }
    while (!q.empty()) {
        auto a = q.front(); q.pop();
        monsterdist[a.first][a.second]=a.dist;
        for (int i=0; i<4; i++) {
            int newx=a.first+dx[i],newy=a.second+dy[i];
            if (newx<0||newx>=N||newy<0||newy>=M||monsterdist[newx][newy]!=-1||field[newx][newy]=='#') continue;
            q.push(structure(newx, newy, a.dist+1));
        }
    }
}
bool works=false;
int endx, endy;
void floodfill() {
    bool visited[N+1][M+1];
    memset(visited, 0, sizeof(visited));
    queue<structure> q;
    q.push({start.first, start.second,0});
    visited[start.first][start.second]=true;
    while (!q.empty()) {
        auto hi=q.front(); q.pop();
        int x=hi.first, y=hi.second, dist=hi.dist;
        //printf("Processing %d, %d\n", x, y);
        if (x==0||x==N-1||y==0||y==M-1) {
            endx=x,endy=y;
            works=true;
            break;
        }

        for (int i=0; i<4; i++) {
            int newx=x+dx[i],newy=y+dy[i];
            if (newx<0||newx>=N||newy<0||newy>=M||field[newx][newy]=='#'||visited[newx][newy]||(monsterdist[newx][newy]!=-1&&monsterdist[newx][newy]<=dist+1)) continue;
            visited[newx][newy]=true;
            track[newx][newy]={x,y};
            path[newx][newy]=letters[i];
            q.push({newx,newy,dist+1});
        }
    }
}
int main() {
    cin >> N>> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> field[i][j];
            if (field[i][j]=='M') monsters.push_back({i,j});
            if (field[i][j]=='A') start={i,j};
        }
    }
    memset(monsterdist,-1,sizeof(monsterdist));
    memset(mydist,-1,sizeof(mydist));
    createmonsterdist();
    floodfill();
    if (works) {
        cout << "YES" << endl;
        vector<char> ans;
        while (field[endx][endy]!='A') {
            ans.push_back(path[endx][endy]);
            auto hi=track[endx][endy];
            endx=hi.first, endy=hi.second;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto hi:ans) {
            cout << hi;
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

}
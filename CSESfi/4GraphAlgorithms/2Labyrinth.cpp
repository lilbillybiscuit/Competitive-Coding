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
int N, M; char field[1005][1005], path[1005][1005];
pii track[1005][1005];
bool visited[1005][1005];
pii start, end1;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
string letters="DRUL";
struct triplet {
    int first, second, dist;
};
bool works=false;
void floodfill() {
    queue<triplet> q;
    q.push({start.first, start.second,0});
    visited[start.first][start.second]=true;
    while (!q.empty()) {
        auto hi=q.front(); q.pop();
        int x=hi.first, y=hi.second, dist=hi.dist;
        //printf("Processing %d, %d\n", x, y);
        if (field[x][y]=='B') {
            works=true;
            break;
        }

        for (int i=0; i<4; i++) {
            int newx=x+dx[i],newy=y+dy[i];
            if (newx<0||newx>=N||newy<0||newy>=M||field[newx][newy]=='#'||visited[newx][newy]) continue;
            visited[newx][newy]=true;
            track[newx][newy]={x,y};
            path[newx][newy]=letters[i];
            q.push({newx,newy,dist+1});
        }
    }
}
int main() {
    cin >> N >> M;
    for (int i = 0; i <N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> field[i][j];
            if (field[i][j]=='A') start={i,j};
            if (field[i][j]=='B') end1={i,j};

        }
    }
    memset(visited,0,sizeof(visited));
    visited[start.first][start.second]=true;
    floodfill();
    if (works) {
        cout << "YES" << endl;
        string ans;
        int curx=end1.first,cury=end1.second;
        while (field[curx][cury]!='A') {
            ans.push_back(path[curx][cury]);
            auto hi=track[curx][cury];
            curx=hi.first;
            cury=hi.second;
        }
        reverse(ans.begin(),ans.end());
        cout << ans.size() << endl;
        for (auto hi : ans) cout << hi;
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}
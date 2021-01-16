using namespace std;

#include <bits/stdc++.h>
#define timerstart chrono::high_resolution_clock::time_point MFA83N03MF = chrono::high_resolution_clock::now();
#define timerend cout << ((chrono::duration<double, std::milli>)(chrono::high_resolution_clock::now() - MFA83N03MF)).count() << endl;

typedef pair<int, int> pii;
typedef long long ll;
int N, K;
char field[1005][1005];
int walldist[1005][1005];
struct State {
    int x, y,dist;
};
struct State2 {
    int x, y, depth;
    bool lastmoved;
};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int replication[1005][1005];int depthleft[1005][1005];
queue<State> bfs1;
queue<State2> bfs2;
queue<State2> combine;
int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> field[i][j];
        }
    }
    timerstart
    memset(walldist, -1, sizeof(walldist));
    memset(replication, 0, sizeof(replication));
    for (int i=0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (field[i][j]=='#') {
                bfs1.push({i, j, 0});
            }
        }
    }

    while (!bfs1.empty()) {
        auto hi = bfs1.front(); bfs1.pop();
        if (walldist[hi.x][hi.y]!=-1) continue;
        walldist[hi.x][hi.y]=hi.dist;
        for (int i=0; i<4; i++) {
            int newx=hi.x+dx[i],newy=hi.y+dy[i];
            if (walldist[newx][newy]!=-1) continue;
            bfs1.push({newx, newy, hi.dist + 1});
        }
    }
    /*
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << walldist[i][j];
        }
        cout << endl;
    }*/


    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (field[i][j]=='S') {
                bfs2.push({i,j,0, false});
            }
        }
    }
    bool visited1[1005][1005];
    memset(visited1, 0, sizeof(visited1));
    while (!bfs2.empty()) {
        auto hi=bfs2.front(); bfs2.pop();
        int radius= hi.depth / K + 1; //If hi.depth==0 (beginning), then radius=1;
        //If hi.depth==1, then radius=1 if K=2
        //If hi.depth==2, then radius=2 if K=2 since it replicated
        //cout << radius << " " << hi.x << " " << hi.y << endl;
        if (visited1[hi.x][hi.y]) continue;
        if (walldist[hi.x][hi.y]==0) continue;

        if (radius<replication[hi.x][hi.y]) continue;
        if (hi.depth%K==0&&hi.depth>0) { //If you expand the radius this round, see if you can get to the
                                         //square before testing extending the radius
            radius--;
        }
        if (radius>walldist[hi.x][hi.y]) continue;
        replication[hi.x][hi.y]=radius;
        if (hi.depth%K==0&&hi.depth>0) { //Now test increasing the radius
            radius++;
        }
        if (hi.x==5&&hi.y==1) {
            //cout << "DEPTH: " << hi.depth << endl;
        }
        if (radius>walldist[hi.x][hi.y]) continue;
        replication[hi.x][hi.y]=radius;
        //cout << radius << " " << walldist[hi.x][hi.y] << endl;
        visited1[hi.x][hi.y]=true;

       /* bool temp=hi.depth%K==0;

        if (hi.depth%K==0) {
            if (radius <= walldist[hi.x][hi.y]) {
                replication[hi.x][hi.y]=radius;
            }
        }

        if (radius > walldist[hi.x][hi.y]) continue;


        if (radius == walldist[hi.x][hi.y]) {
            replication[hi.x][hi.y]=radius;
        } else {
            replication[hi.x][hi.y]=radius;
        }*/

        for (int i=0; i<4; i++) {
            int newx=hi.x+dx[i],newy=hi.y+dy[i];
            if (visited1[newx][newy]||walldist[newx][newy]==0) continue;
            bfs2.push({newx,newy,hi.depth+1});
        }
    }
    //cout << "FINISHED bfs2" << endl;
    /*cout << "---------------REPLICATION---------------" << endl;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << replication[i][j];
        }
        cout << endl;
    }*/
    bool visited[1005][1005];
    memset(visited, 0, sizeof(visited));

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (replication[i][j]>0) {
                combine.push({i, j, replication[i][j]});
            }

        }
    }
    //cout << "FINISHED ADDING INTO QUEUE" << endl;

    memset(depthleft, 0, sizeof(depthleft));
    while (!combine.empty()) {
        auto hi = combine.front(); combine.pop();
        //cout << hi.x << " " << hi.y << " " << hi.depth << " size: " << combine.size() << endl;
        if (hi.depth==0||hi.depth<=depthleft[hi.x][hi.y]) continue;

        depthleft[hi.x][hi.y]=hi.depth;
        visited[hi.x][hi.y]=true;
        for (int i=0; i<4; i++) {
            int newx=hi.x+dx[i],newy=hi.y+dy[i];
            if (hi.depth==1||hi.depth-1<depthleft[newx][newy]) continue;
            combine.push({newx,newy,hi.depth-1});
        }
    }
    //cout << "--------------FINAL---------------" << endl;
    int ans=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (visited[i][j]) {
                ans++;
                //cout << 'x';
            } else {
                //cout << field[i][j];
            }
        }
        //cout << endl;
    }
    cout << ans << endl;
    //timerend
}
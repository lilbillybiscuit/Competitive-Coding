using namespace std;

#include <bits/stdc++.h>

typedef pair<int, int> pii;
typedef long long ll;
int N, ans=0;

unordered_map<int, int> lookupy; //lookupy table corresponding y value to the x value
struct Point {
    int x, y;
};
Point points[205];

struct BIT { //Might need more than one
    int tree[300];
    BIT() {
        memset(tree, 0, sizeof(tree));
    }
    int get(int ind) {
        int sum=0;
        while (ind > 0) {
            sum+=tree[ind];
            ind-=(ind & -ind);
        }
        return sum;
    }
    void update(int ind, int val) {
        while (ind <= N) {
            tree[ind]+=val;
            ind+=(ind & -ind);
        }
    }

    int range(int i, int j) { //Returns number of cows between the two y values
        return get(j)-get(i-1);
    }
};
int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        int a, b; cin >> a >> b; points[i].x = a; points[i].y = b;
    }
    sort(points, points+N, [&](Point a, Point b) { //Sort by increasing y coordinate for lookupy
        return a.y < b.y;
    });
    //Generate lookupy tables for y coordinate
    //lookupy[ycoord here] --> numbering in list
    for (int i=0; i<N; i++) {
        lookupy[points[i].y]=i;
    }

    sort(points, points+N, [&](Point a, Point b) { //Sort by increasing x coordinate for line sweep
        return a.x < b.x;
    });
    auto ptexistsbefore=[&](int squaremin, int squaretop, int squarebottom) {
        //IMPLEMENT
        return true;
    };
    for (int i=0; i<N; i++) {
        Point pt=points[i];
        int curmax=pt.y,curmin=pt.y;
        set<int> hi;
        BIT ypos;
        ypos.update(lookupy[pt.y], 1);
        hi.insert(pt.y);
        //Start line sweep
        for (int j=i+1; j<N; j++) {
            Point curpt=points[j];
            int squarex=abs(curpt.x-pt.x),squarey=abs(curpt.y-pt.y); //Get minimum square length
            if (curpt.y<pt.y) { //below the line, 2 possible points
                if (squarex<squarey) { //longer height, could extend backwards

                } else if (squarey<squarex) { //short height

                } else { //Perfect square
                    ans++;
                }
            } else {

            }
        }
    }
    cout << ans+N+1 << endl;
}
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
int N, M; char field[1005][1005];

void floodfill(int r, int c) {
    if (r<0||r>=N||c<0||c>=M||field[r][c]!='.') return;
    field[r][c]='s';
    if (field[r+1][c]=='.') {
        floodfill(r+1,c);
    }
    if (field[r-1][c]=='.') {
        floodfill(r-1,c);
    }
    if (field[r][c+1]=='.') {
        floodfill(r,c+1);
    }
    if (field[r][c-1]=='.') {
        floodfill(r,c-1);
    }
    return;

}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> field[i][j];
        }
    }
    int ind=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (field[i][j]=='.') {
                floodfill(i,j);
                ind++;
            }
        }
    }
    cout << ind << endl;

}
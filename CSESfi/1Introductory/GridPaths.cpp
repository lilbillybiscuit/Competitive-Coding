using namespace std;

#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <utility>
#include <algorithm>
#include <cstring>

typedef pair<int, int> pii;
typedef vector <pii> vpii;
typedef vector<int> vi;
typedef long long ll;

string path;
bool visited[8][8];
ll ans=0;

int convert(char a) {
    if (a=='U') {
        return 0;
    } else if (a=='D') {
        return 1;
    } else if (a=='L') {
        return 2;
    } else if (a=='R') {
        return 3;
    } else if (a=='?') {
        return -1;
    }
    return -1;
}
char convertchar(int a) {
    if (a==0) {
        return 'U';
    } else if (a==1) {
        return 'D';
    } else if (a==2) {
        return 'L';
    } else if (a==3) {
        return 'R';
    } else if (a==-1) {
        return '?';
    }
}

bool prune(int row, int col) {
    if (visited[row][col]) return false;
    if (row>0&&row<6&&col>0&&col<6) {
        if (visited[row+1][col]&&visited[row-1][col]&&!visited[row][col+1]&&!visited[row][col-1]) return false;
        if (!visited[row+1][col]&&!visited[row-1][col]&&visited[row][col+1]&&visited[row][col-1]) return false;
    } else if (col>0&&col<6) {
        if (!visited[row][col+1]&&visited[row][col-1]) {
            if ((row==0&&visited[row+1][col]) || (row==6&&visited[row-1][col])) return false;
        }
    } else if (row>0&&row<6) {
        if (!visited[row+1][col]&&!visited[row-1][col]) {
            if ((col==0&&visited[row][col+1]) || (col==6&&visited[row][col-1])) return false;
        }
    }
    return true;
}
bool prune1(int row, int col) {
    return visited[row][col]||((col > 0 && col < 6 && !visited[row][col + 1] && !visited[row][col - 1] &&
     ((row == 0 && visited[row + 1][col]) || (row == 6 && visited[row - 1][col]))) ||
    (row > 0 && row < 6 && !visited[row + 1][col] && !visited[row - 1][col] &&
     ((col == 0 && visited[row][col + 1]) || (col == 6 && visited[row][col - 1]))))
    || (row > 0 && row < 6 && col > 0 && col < 6 && visited[row - 1][col] && visited[row + 1][col] && !visited[row][col - 1] && !visited[row][col + 1])
       || (row > 0 && row < 6 && col > 0 && col < 6 && visited[row][col - 1] && visited[row][col + 1] && !visited[row - 1][col] && !visited[row + 1][col]);
}

void search(int row, int col, int steps) {
    if (row<0||col<0||col>6||row>6) return;
    if (row==6&&col==0) {
        if (steps == 48) ans++;
        return;
    }
    if (prune1(row,col)) return;
    visited[row][col] =true;
    if (path[steps]=='?') {
        search(row,col-1,steps+1);
        search(row, col+1,steps+1);
        search(row-1, col, steps+1);
        search(row+1, col, steps+1);
    } else if (path[steps]=='U'&&row>0) {
        search(row-1,col,steps+1);
    } else if (path[steps]=='D'&&row<6) {
        search(row+1, col,steps+1);
    } else if (path[steps]=='L'&&col>0) {
        search(row, col-1, steps+1);
    } else if (path[steps]=='R'&&col<6) {
        search(row, col+1, steps+1);
    }
    visited[row][col]=false;
}
int main() {
    memset(visited, 0, sizeof(visited));
    cin >> path;
    search(0,0,0);
    cout << ans << endl;
}
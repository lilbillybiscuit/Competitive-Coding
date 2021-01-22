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
char chess[8][8];
ll ans=0;
int path[8];
bool canplace(int index, int loc) {
    if (chess[index][loc]=='*') return false;
    for (int i=0; i<index; i++) {
        if (path[i]==loc) return false;
    }
    for (int i=index,j=loc; i>=0&&j<8; i--,j++) {
        if (path[i]==j) return false;
    }
    for (int i=index,j=loc; i>=0&&j>=0;i--,j--) {
        if (path[i]==j) return false;
    }

    return true;
}
void process(int index) {
    if (index==8) {
        ans++;
        return;
    }
    for (int i=0; i<8; i++) {
        if (canplace(index, i)) {
            path[index]=i;
            process(index+1);
            path[index]=-1;
        }
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> chess[i][j];
        }
    }
    memset(path, -1, sizeof(path));
    process(0);
    cout << ans << endl;

}
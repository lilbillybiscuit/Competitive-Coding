using namespace std;

#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <utility>
#include <algorithm>

typedef pair<int, int> pii;
typedef vector <pii> vpii;
typedef vector<int> vi;
typedef long long ll;

int main() {
    //whichever x or y is higher dictates the row
    int T; cin >> T;
    for (int i=0; i<T; i++) {
        ll x, y; cin >> y >> x;
        if (y>x) { //On column y
            if (y%2==0) {
                cout << y*y-x+1;
            } else {
                cout << (y-1)*(y-1)+x;
            }
        } else if (y<x) {
            if (x%2==0) {
                cout << (x-1)*(x-1)+y;
            } else {
                cout << x*x-y+1;
            }
        } else if (y==x) {
            cout << (x-1)*(x-1)+x;
        }
        cout << endl;
    }
}
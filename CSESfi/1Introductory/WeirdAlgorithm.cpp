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
    ll N;
    cin >> N;
    while (N!=1) {
        cout << N << " ";
        if (N%2==0) {
            N/=2;
        } else {
            N=N*3+1;
        }
    }
    cout << 1 << endl;
}
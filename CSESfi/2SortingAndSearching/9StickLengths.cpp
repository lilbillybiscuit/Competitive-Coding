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

int N;
int sticks[200005];

int main() {
     cin >> N;  for (int i = 0; i <N; i++) cin >>sticks[i];
     sort(sticks, sticks+N);
     int goal=sticks[N/2];
     ll ans=0;
     for (int i = 0; i < N; i++) {
         ans+=abs(sticks[i] - goal);
     }
     cout << ans << endl;
}
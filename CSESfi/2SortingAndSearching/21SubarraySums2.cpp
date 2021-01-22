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
int N, nums[200005], X;
//Basically exact copy of Subarray Sums 1
int main() {
    cin >> N>>X;
    map<ll, int> prefix;
    ll temp=0;
    ll ans=0;
    prefix[temp]+=1;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        temp+=nums[i];
        auto hi=prefix.find(temp-X);
        if (hi!=prefix.end()) ans+=hi->second;
        prefix[temp]+=1;
    }
    cout << ans << endl;


}
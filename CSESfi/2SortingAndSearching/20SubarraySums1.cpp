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
    /*int prefix[N+1];
    prefix[0]=0;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        prefix[i+1]=prefix[i]+nums[i];
    }
    int ans=0;
    for (int i = 0; i < N; i++) {
        int find=prefix[i+1]-X;
        if (find<0) continue;
        if (nums[i]==X) {
            ans++; continue;
        }
        int left=0, right=i;
        while (left<right) {
            int mid=(left+right)/2;
            if (prefix[mid]>find) {
                //printf("%d: too much\n", prefix[mid]);
                right=mid;
            } else if (prefix[mid]<find){
                //printf("%d: too little\n", prefix[mid]);
                left=mid+1;
            } else {
                //printf("%d worked", prefix[mid]);
                ans++;
                break;
            }
        }
    }*/
    cout << ans << endl;


}
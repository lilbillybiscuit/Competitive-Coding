#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
int N;
pll cows[5005];
bool ysort (pll a, pll b) {
    
}
bool xsort (pll a, pll b) {
    return a.first < b.first;
}

ll tree[5005];

void update(int i, ll num) {
    while (i <= N) {
        tree[i]+=num;
        i+=(i & -i);
    }
}
ll get(int i) {
    ll sum=0;
    while (i > 0) {
        sum+=tree[i];
        i-=(i & -i);
    }
    return sum;
}
long long range(int i, int j) {
    return get(j)-get(i-1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    //Coord Compression
    sort(cows, cows+N,[&](pii a, pii b) {
        return a.second < b.second;
    });
    for (int i=0; i<N; i++) cows[i].second=i+1;
    sort(cows, cows+N,[&](pll a, pll b) {
        return a.first < b.first;
    });
    for (int i=0; i<N; i++) cows[i].first=i+1;

    ll ans=0;
    for (int i=0; i<N; i++) {
        memset(tree,0,sizeof(tree));
        auto index=cows[i];
        ll curmax=index.second,curmin=index.second;
        for (int j=i+1; j<N; j++) {
            ll cury=cows[j].second;
            ll cows1,cows2;
            if (cury < index.second) {


                if (cury<curmin) {
                    curmin=cury;
                    cows1=range(1, N);
                    cows1=range(index.second, N);
                    ans+= cows1 + 1;
                    update(cury,1);
                } else {
                    cows1= range(1, cury),cows2=range(index.second, N);
                    ans+= cows1+cows2+cows1*cows2 + 1;
                    update(cury,1);
                }
            } else {
                if (cury>curmax) {
                    curmax=cury;
                    cows1=range(1, index.second);
                    ans+= cows1 + 1;
                    update(cury,1);
                } else {
                    cows1= range(cury, N),cows2=range(1, index.second);
                    ans+= cows1 + cows2+cows1*cows2 + 1;
                    update(cury,1);
                }
            }
        }
    }
   cout << ans+N+1 << endl;
}
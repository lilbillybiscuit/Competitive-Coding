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
    int N, M, K; cin >> N >> M >> K;
    int applicants[200005],apartments[200005];
    for (int i = 0; i < N; i++) {
        cin >> applicants[i];
    }
    for (int i=0; i < M; i++) {
        cin >> apartments[i];
    }
    sort(applicants,applicants+N);
    sort(apartments,apartments+M);
    int i=0,j=0,ans=0;
    while (i<N&&j<M) {
        int high=apartments[j]+K,low=apartments[j]-K;
        if (high>=applicants[i]&&applicants[i]>=low) {
            ans++; i++,j++;

        } else if (applicants[i]>high) {
            j++;
        } else if (applicants[i]<low) {
            i++;
        }
    }
    cout << ans << endl;
}
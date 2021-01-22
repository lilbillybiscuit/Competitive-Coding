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
    int N; cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    int ans=1, last=arr[0];
    for (int i=1; i<N; i++) {
        if (arr[i]!=last) {
            last=arr[i];
            ans++;
        }
    }
    cout << ans << endl;
}
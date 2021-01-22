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
    ll total=0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < N; i++) {
        if (arr[i-1]>arr[i]) {
            total+=arr[i-1]-arr[i];
            arr[i] = arr[i-1];
        }
    }
    cout << total << endl;
}
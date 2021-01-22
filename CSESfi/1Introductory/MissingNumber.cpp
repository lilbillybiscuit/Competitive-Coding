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
    int nums[N-1];
    for (int i=0; i<N-1; i++) {
        cin >> nums[i];
    }
    bool printed=false;
    sort(nums, nums+N-1);
    for (int i=0; i<N-1; i++) {
        if (nums[i]!=i+1) {
            cout << i+1 << endl;
            printed=true;
            break;
        }
    }
    if (!printed) cout << N << endl;
}
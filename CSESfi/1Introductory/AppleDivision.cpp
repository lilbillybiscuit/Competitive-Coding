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
int N, apples[25];
ll minimum=INT_MAX;

int bruteforce(int index, ll val1, ll val2) {
    if (index==N) {
        return minimum=min(minimum, abs(val1-val2));
    }
    bruteforce(index+1,val1+apples[index], val2);
    bruteforce(index+1,val1,val2+apples[index]);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> apples[i];
    }
    bruteforce(0,0,0);
    cout << minimum << endl;
}
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

typedef pair<int, int> pii;
typedef vector <pii> vpii;
typedef vector<int> vi;
typedef long long ll;
int N;
pii tasks[200005];
int main() {
    cin >> N; for (int i = 0; i < N; i++) cin >> tasks[i].first >> tasks[i].second;
    sort(tasks, tasks+N);
    ll time=0, sum=0;
    for (int i = 0; i < N; i++) {
        int duration = tasks[i].first, deadline=tasks[i].second;
        time+=duration;
        sum+=deadline-time;
    }
    cout << sum << endl;
}
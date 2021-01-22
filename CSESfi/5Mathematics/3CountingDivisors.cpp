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
vector<int> primes;
void initialize() {
    primes.push_back(2);
    for (int i=3; i<10000; i++) {
        bool works=true;
        for (int hi:primes) {
            if (i%hi==0) {
                works=false; break;
            }
        }
        if (works) primes.push_back(i);
    }
}
int process(int a) {
    int ans=1;
    for (int i=0; i<primes.size(); i++) {
        if (a==1||primes[i]>a) break;
        int curprime=primes[i];
        int count=0;
        while (a%curprime==0) {
            count++;
            a/=curprime;
        }
        ans*=count+1;
    }
    if (a>2) return 2*ans;
    return ans;
}
int main() {
    initialize();
    int N; cin >> N;
    for (int i = 0; i<N; i++) {
        int a; cin >> a;
        cout << process(a) << endl;
    }
}
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
int N, books[200005];
bool check(ll maxlength) {
    ll total1=0, total2=0;
    int i=0, j=N-1;
    while (i<=j) {
        total2+=books[j]; j--;
        if (total2 > maxlength) {
            j++;
            total2-=books[j];
            if (total1+books[j]>maxlength) {

            }
        }
        while (total1<=total2&&i<=j) {
            total1+=books[i]; i++;
        }  
    }
    return total1 < maxlength && total2 < maxlength;
}
int main() {
    cin >> N; for (int i = 0; i < N; i++) { cin >> books[i]; }
    sort(books, books+N);
    ll left=0, right=LLONG_MAX;
    while (left < right) {
        ll mid=(left+right)/2;
        if (check(mid)) {
            right=mid;
        } else {
            left=mid+1;
        }
    }
    cout << right << endl;
}
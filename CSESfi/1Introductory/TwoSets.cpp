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
    if (N%4==1 || N%4==2) {
        cout << "NO" << endl;
        return 0;
    } else {
        cout << "YES" << endl;
    }
    vector<int> set1, set2;
    bool go1=true;
    if (N%2==1) {
        bool special1=false;
        if (N%8==3) {
            int mid=N/2+1;
            for (int i = 1; i <= N/2; i++) {
                if (go1) {
                    if (i!=mid/2) set1.push_back(i);
                    else special1=true;
                    set1.push_back(N-i+1);
                    go1=false;
                } else {
                    if (i!=mid/2) set2.push_back(i);
                    set2.push_back(N-i+1);
                    go1=true;
                }
            }
            if (go1) {//set 2 got the last element
                set1.push_back(mid);
                set1.push_back(mid/2);
            } else {
                set2.push_back(mid);
                set2.push_back(mid/2);
            }
        } else {
            int mid=N/2+1;
            for (int i = 2; i <= N/2; i++) {
                if (go1) {
                    if (i!=mid/2) set1.push_back(i);
                    else special1=true;
                    set1.push_back(N-i+1);
                    go1=false;
                } else {
                    if (i!=mid/2) set2.push_back(i);
                    set2.push_back(N-i+1);
                    go1=true;
                }
            }
            if (special1) {//set 1 is missing an element
                set2.push_back(mid);
                set2.push_back(mid/2);
                set1.push_back(N);
                set1.push_back(1);
            } else {
                set1.push_back(mid);
                set1.push_back(mid/2);
                set2.push_back(N);
                set2.push_back(1);
            }
        }
    } else {
        bool go1=true;
        for (int i = 1; i <= N/2; i++) {
            if (go1) {
                set1.push_back(i);
                set1.push_back(N-i+1);
                go1=false;
            } else {
                set2.push_back(i);
                set2.push_back(N-i+1);
                go1=true;
            }

        }
    }
    cout << set1.size() << endl;
    sort(set1.begin(), set1.end());
    for (int i=0; i<set1.size(); i++) {
        cout << set1[i];
        if (i!=set1.size()-1) cout << " ";
    }
    cout << endl;
    cout << set2.size() << endl;
    sort(set2.begin(), set2.end());
    for (int i=0; i<set2.size(); i++) {
        cout << set2[i];
        if (i!=set2.size()-1) cout << " ";
    }
    cout << endl;

}
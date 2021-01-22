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
    string s; cin >> s;
    char str[s.length()];
    for (int i = 0; i < s.length(); i++) {
        str[i] = s[i];
    }
    sort(str, str+s.length());
    char palendrome[s.length()];
    char extrachar=0;
    int palenindex=0;
    for (int i = 0; i < s.length(); i+=2) {
        if (str[i]==str[i+1]) {
            palendrome[palenindex]=str[i];
            palendrome[s.length()-1-palenindex]=str[i+1];
            palenindex++;
        } else {
            if (extrachar==0) {
                extrachar=str[i];
                i--;
            } else {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
        }
    }
    if (extrachar!=0) {
        palendrome[palenindex]=extrachar;
    }
    for (auto a : palendrome) cout << a;
    cout << endl;
}
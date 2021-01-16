#include <bits/stdc++.h>
using namespace std;
int N, answers = 0;
vector<int> node,power2;

int maxpower(int num) {
    for (int i = 0; i < power2.size(); i++) if (num <= power2[i]) return i;
    return 0;
}

int main() {
    cin >> N; node.assign(N, 0);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a>>b; node[a - 1]++, node[b - 1]++;
    }
    for (int i = 0; i < 32; i++) power2.push_back(pow(2.0, i));
    
    answers+=maxpower(node[0] + 1);
    for (int i = 1; i < N; i++) {
        answers+=maxpower(node[i]);
    }
    cout << answers + (N - 1) << endl;
}
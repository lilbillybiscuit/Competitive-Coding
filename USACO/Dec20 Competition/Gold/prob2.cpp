using namespace std;

#include <bits/stdc++.h>

typedef pair<int, int> pii;
typedef long long ll;
string s;
int seq[1000005],N;

vector<int> qmarks;

int dp[1000005][4][4][4];


void dynamic(int &i, int &first, int &required, int &lastput, int &curput) {
    //first=first element of block, required=required last element of block
    //lastput=last block placed
    if (lastput != curput) {
        dp[i+1][first][required][curput]+=dp[i][first][required][lastput];
        dp[i+1][first][required][curput]%=(int)1e9 + 7;
    }

    if (lastput == required) {//if the last block placed = the required element of the last block, then break it here
        //New block starts with curput
        dp[i+1][curput][first][curput]+=dp[i][first][required][lastput];
        dp[i+1][curput][first][curput]%= (int)1e9 + 7;
        required=first;
        first=curput;

    }
    lastput=curput;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    getline(cin, s);
    N=s.length();
    for (int i=0; i<N; i++) {
        if (s[i]=='T') seq[i]=0;
        if (s[i]=='A') seq[i]=1;
        if (s[i]=='G') seq[i]=2;
        if (s[i]=='C') seq[i]=3;
        if (s[i]=='?') {
            seq[i]=4; // The unknown seq is marked with a 4
            qmarks.push_back(i);
        }
    }
    memset(dp, 0, sizeof(dp));
    //finish reading input into seq;
    int a=seq[0],b=0,c=0; //B doesn't have to be anything yet
                           //C hasn't been picked yet
    //a=first element of block, b=required last element of block
    //c=last block placed
    dp[0][a][b][c]=1;
    cout <<"start" << " " <<  a << " " << b << " " << c << " " << endl;

    for (int i=0; i<N; i++) {
        if (seq[i] == 4) { //it's a question mark
            for (int x=0; x<=3; x++) {
                dynamic(i,a,b,c,x);
                cout <<i << " " <<  a << " " << b << " " << c << " " << "x: " << x << endl;
            }
        } else { //it's already set
            dynamic(i, a, b, c, seq[i]);
            /*if (i<N-1&&seq[i]==seq[i+1]&&seq[i]!=0) {
                //force split here
            }*/

        }
        cout <<i << " " <<  a << " " << b << " " << c << " " << endl;

    }
    ll ans=0;
    for (int i=0; i<=4; i++) {
        for (int j=0; j<=4; j++) {
            for (int k=0; k<=4; k++) {
                ans+=dp[N][i][j][k];
            }
        }
    }
    cout << ans << endl;

}
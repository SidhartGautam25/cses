#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

void solutionOne() {

    ll mxN = 1e6+6;
    ll dp[mxN][3];

    dp[1][1] = dp[1][2] = 1;
    for (ll i = 2; i < mxN; i++) {
        dp[i][1] = (dp[i-1][1]*4%MOD + dp[i-1][2])%MOD;
        dp[i][2] = (dp[i-1][1] + dp[i-1][2]*2%MOD)%MOD;
    }







    ll t;
    cin >> t;

    while (t--) {
       ll n;
       cin>>n;

       cout<<(dp[n][1] + dp[n][2])%MOD<<endl;

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solutionOne();
    return 0;
}

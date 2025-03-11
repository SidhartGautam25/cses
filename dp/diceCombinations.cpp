#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007




void solutionOne(){

    ll n;
    cin>>n;

    vector<ll>dp(n+1);
    dp[1]=1;
    dp[0]=1;

    for(ll i=2;i<=n;i++){

        for(ll j=1;j<=6;j++){
            ll mov=i-j;
            if(mov>=0){
               dp[i]=((dp[i]%mod)+(dp[mov]%mod))%mod;
            }
        }

    }


    cout<<dp[n]<<endl;




   



}

int main(){

    solutionOne();

    return 0;
}
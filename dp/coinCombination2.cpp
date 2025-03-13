#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007



void solutionOne(){

    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    vector<int>dp(x+1);
    dp[0]=1;


    for(int i=0;i<n;i++){
        int coin=coins[i];
        for(int j=1;j<=x;j++){
            if(j-coin>=0){
                dp[j]=(dp[j]+dp[j-coin])%mod;
            }
        }
    }

    cout<<dp[x]<<endl;
 


}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    solutionOne();

    return 0;
}
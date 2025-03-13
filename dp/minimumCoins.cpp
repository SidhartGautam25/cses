#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod ll_MAX



void solutionOne(){

    int n,x;
    cin>>n>>x;

    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    vector<int>dp(x+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            int coin=coins[j];
            if(i-coin>=0 && dp[i-coin] != INT_MAX){
                dp[i]=min(dp[i],dp[i-coin]+1);
            }
        }
    }

    if(dp[x] != INT_MAX){
        cout<<dp[x]<<endl;

    }else{
        cout<<"-1"<<endl;
    }
    


  
    

    

  




}

int main(){

    solutionOne();

    return 0;
}
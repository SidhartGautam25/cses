#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007



void solutionOne(){

   int n;
   cin>>n;

   vector<vector<int>>grid(n,vector<int>(n,0));

   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          char c;
          cin>>c;
          if(c=='*'){
               grid[i][j]=1;
          }
      }
   }
   if(grid[0][0]==1){
       cout<<"0"<<endl;
       return;
   }

   vector<vector<int>>dp(n,vector<int>(n,0));
   dp[0][0]=1;
   
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if( i>0 || j>0){
            if(grid[i][j]==0){
                if(j-1>=0){
                     dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
                }
                if(i-1>=0){
                     dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
                }   
            }
        }
    }
   }

   cout<<dp[n-1][n-1]<<endl;

}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    solutionOne();

    return 0;
}
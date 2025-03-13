#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007



void solutionOne(){

   int n;
   cin>>n;

   vector<ll> dp(n+1,INT_MAX);

   dp[0]=0;
   for(int i=1;i<=n;i++){
      int t=i;
      while(t){
        int d=t%10;
        dp[i]=min(dp[i],dp[i-d]+1);
        t=t/10;
      }
   }

   cout<<dp[n]<<endl;

}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    solutionOne();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007



// diagonal dp
void solutionOne() {

    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    
   vector<vector<ll>>dp(n,vector<ll>(n));

   vector<ll>sum(n+1);
   ll s=0;
   sum[0]=0;
   for(ll i=1;i<=n;i++){
      s=s+arr[i-1];
      sum[i]=s;
   }
   
   for(ll diff=0;diff<n;diff++){
      ll i=0;
      while(i+diff<n){
          ll j=i+diff;
          if(diff==0){
             dp[i][j]=arr[i];
          }else if(diff==1){
            dp[i][j]=max(arr[i],arr[j]);
          }else{
            dp[i][j]=max(arr[i]+((sum[j+1]-sum[i+1])-dp[i+1][j]),arr[j]+((sum[j]-sum[i])-dp[i][j-1]));


          }
          i++;
      }
      


   }

   cout<<dp[0][n-1]<<endl;
   



}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solutionOne();

    return 0;
}

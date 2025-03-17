#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll mod_inv(ll a, ll m) {
    ll res = 1, power = m - 2;
    while (power) {
        if (power % 2) res = (res * a) % m;
        a = (a * a) % m;
        power /= 2;
    }
    return res;
}


// using 2D array dp
void solutionOne(){

   ll n;
   cin>>n;
   ll sum=0;
   vector<ll>arr(n);
   for(ll i=1;i<=n;i++){
        arr[i-1]=i;
        sum=sum+arr[i-1];
   }

   if(sum%2==1){
      cout<<"0"<<endl;
      return;
   }
   ll size=n;
   ll target=sum/2;
   vector<vector<ll>>dp(size+1,vector<ll>(target+1,0));

   for(ll i=0;i<=size;i++){
       for(ll j=0;j<=target;j++){
           if(j==0){
               dp[i][j]=1;

           }else if(i==0){
               dp[i][j]=0;

           }else{
              dp[i][j]=dp[i][j]+dp[i-1][j];
              if(j-arr[i-1]>=0){
                   dp[i][j]=((dp[i][j]%mod)+(dp[i-1][j-arr[i-1]]%mod))%mod;


              }
              
           }
       }
   }

   ll ans=(dp[size][target] * mod_inv(2, mod)) % mod; 
   cout<<ans<<endl;


}



void solutionTwo(){
    
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    solutionOne();

    return 0;
}
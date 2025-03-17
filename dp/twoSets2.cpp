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


// using 1D array
void solutionTwo(){
     ll n;
    cin >> n;

    ll sum = n * (n + 1) / 2;  // Sum of first n natural numbers

    if (sum % 2 == 1) {
        cout << "0" << endl;
        return;
    }

    ll target = sum / 2;
    vector<ll> dp(target + 1, 0);
    dp[0] = 1;

    for (ll i = 1; i <= n; i++) {

        // very important to understand why we are moving in reverse order
        // hmlogo ka logic ye hai ki hr ek element ko utha kr ye decide 
        // kr rhe ki usse koi target(i) kitne trike se bnaya ja sakta hai
        // to maan lete hai 1,2....5 tk element ko hmlog consider kr lie hai
        // or ab hmlog 6 ki madad se let's say 10 ko bnana chahte hai
        // iska mtlb dp[10] ko bnana hai
        // to agr socha jae to dp[10] ko 6 tk number se banane ka total trika
        // utna hoga jitna abhi tk mtlb dp[10] abhi tk 5 tk ke lie to store 
        // kia hi hua hai ki kitne trike se bna sakte hai
        // to dp[10]=dp[10]+5 tk ko consider krke dp[4] (mtlb 4 kitna trike se bnaya
        // ja sakta hai 5 tk ke number ke help se )
        // ab agr order reverse nhi rahta to hmlog dp[10] ke pahle dp[4] ko solve
        // kr rhe hote iska mtlb hr element ke lie hmlog pahle dp[4] ko solve krte 
        // tb dp[10] me aate lekin dp[10] ko 6 ka consider krke solve krne ke lie 
        // dp[4] me 5 ko hi consider krke bnane itna trika ka number store hona chahie
        // islie hmlog pahle dp[10] ko solve kr rhe kisi ek element ke lie taaki uske 
        // pahle wale number ke dp me dp[4] tk hi answer rhe 
        
        for (ll j = target; j >= i; j--) {  // Iterate in reverse order
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }

    // Divide result by 2 using modular inverse
    cout << (dp[target] * mod_inv(2, mod)) % mod << endl;

}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    solutionOne();

    return 0;
}
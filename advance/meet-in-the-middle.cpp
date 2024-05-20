#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod LLONG_MAX


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<ll,ll, custom_hash> mp_left;


 
 
void solve(){
    //this is dp solution
    // got runtime error because value of sum is too large to handle the size 
    // of the array

    // ll n,sum;
    // cin>>n>>sum;
    // vector<ll>arr(n);
    // for(ll i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    // vector<vector<ll>>dp(sum+1,vector<ll>(n+1,0));
    // for(ll i=0;i<=n;i++){
    //     dp[0][i]=1;
    // }
    // for(ll s=1;s<=sum;s++){
    //     for(ll size=1;size<=n;size++){
    //         if(s-arr[size-1]>=0){
    //             dp[s][size]=dp[s-arr[size-1]][size-1];
    //         }
    //         dp[s][size]=dp[s][size]+dp[s][size-1];
    //     }
    // }
    // cout<<dp[sum][n]<<endl;


    // Meet in the middle technique
    ll n,sum;
    cin>>n>>sum;
    ll s1=n/2;
    ll s2=n-s1;
    vector<ll>left(s1);
    vector<ll>right(s2);

    for(ll i=0;i<n;i++){
        ll temp;
        cin>>temp;
        if(i<n/2){
            left[i]=temp;
        }else{
            right[i-s1]=temp;
        }
    }

    //unordered_map<ll,ll>mp_left;
    
    ll num=1<<s1;
    for(ll i=0;i<num;i++){
        ll s=0;
        for(ll j=0;j<min(i,s1);j++){
            if(i&(1<<j)){
                s=s+left[j];
            }
        }
        mp_left[s]++;
    }

    num=1<<s2;
    ll ans=0;
    for(ll i=0;i<num;i++){
        ll s=0;
        for(ll j=0;j<min(i,s2);j++){
            if(i&(1<<j)){
                s=s+right[j];
            }
        }
        if (mp_left.count(sum-s)) ans += mp_left[sum-s];
    }

   cout<<ans<<endl;


   
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t=1;
    
    //cin>>t;
    while(t--){
        solve();
     }
 
    return 0;
}
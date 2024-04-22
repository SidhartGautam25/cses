#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod LLONG_MAX
 
 
void build_anses_dp(vector<ll>&parent,vector<vector<ll>>&dp){
    ll n=parent.size();
    ll mmax=20;//this number is dur to the case that with 17,we can calculate for any given k upto 10^5
    for(ll i=0;i<n;i++){
        dp[0][i]=parent[i];
    }
    for(ll i=1;i<mmax;i++){
        for(ll j=0;j<n;j++){
            // let say we have to find 8th ansestor,then first we find 4th ansestor,and then again 4th ansestor
            // of the 4th ansestor
            //let say we call 4th ansestor anses1
            //then anses1 will be
            ll anses1=dp[i-1][j];//this is because ith box of j is storing 2^i th ansestor,
            // so 8th ansestor means 2^3,means i equal to 3,then 4th ansestor means 2^2,
            // means i-1,3-1 =2,thats why anses1 is equal to dp[i-1][j]

            // now lets say 8th ansestor be anses2,then anses2 will be 4th ansestor of anses 1;
            // so anses2 will be 
            if(anses1==-1){
                dp[i][j]=-1;
                continue;
            }
            ll anses2=dp[i-1][anses1];
            dp[i][j]=anses2;
        }
    }

}

ll query_for_kth_ansestor(ll node,ll k,vector<vector<ll>>&dp){
    ll mmax=20;
    if(k==0){
        return node;
    }
    for(ll i=0;i<mmax;i++){
        ll mask=(1<<i);
        if((k&mask)>0){
            if(node==-1){
                return node;
            }
            node=dp[i][node];
        }
    }
    return node;
}

void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll>parent(n);
    parent[0]=-1;
    for(ll i=1;i<n;i++){
        ll p;
        cin>>p;
        p--;
        parent[i]=p;
    }
    ll mmax=20;
    vector<vector<ll>>dp(mmax,vector<ll>(n));
    build_anses_dp(parent,dp);
    for(ll i=0;i<q;i++){
        ll x,k;
        cin>>x>>k;
        ll ans=query_for_kth_ansestor(x-1,k,dp);
        if(ans != -1){
            ans++;
        }
        cout<<ans<<endl;
    }
}


int main(){
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}

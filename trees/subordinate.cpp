#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod LLONG_MAX

void dfs(vector<vector<ll>>&tree,ll curr,ll p,vector<ll>&dp){
    dp[curr]=0;
    for(ll i=0;i<tree[curr].size();i++){
        ll child=tree[curr][i];
        if(child != p){
            dfs(tree,child,curr,dp);
            dp[curr]=dp[curr]+dp[child];
            dp[curr]=dp[curr]+1;
        }
    }
}


void solve(){
  
    ll n;
    cin>>n;
    vector<vector<ll>>tree(n+1);
    for(ll i=2;i<=n;i++){
        ll p;
        cin>>p;
        tree[p].push_back(i);
        tree[i].push_back(p);
    }
    vector<ll>dp(n+1);
    dfs(tree,1,1,dp);
    for(ll i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    
   
}


int main(){
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}

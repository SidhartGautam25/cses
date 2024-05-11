#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod LLONG_MAX
 
void dfs(vector<vector<ll>>&tree,ll curr,ll p,vector<ll>&levels,ll l,vector<ll>&parent){
    levels[curr]=l;
    parent[curr]=p;
    for(ll i=0;i<tree[curr].size();i++){
        ll child=tree[curr][i];
        if(child != p){
            dfs(tree,child,curr,levels,l+1,parent);
        }
    }

}
 
void build_anses_dp(vector<ll>&parent,vector<vector<ll>>&dp,ll n){
    ll mmax=18;
    for(ll i=1;i<=n;i++){
        dp[0][i]=parent[i];
    }
    for(ll i=1;i<mmax;i++){
        for(ll j=1;j<=n;j++){
            ll anses1=dp[i-1][j];
            ll anses2=dp[i-1][anses1];
            dp[i][j]=anses2;
        }
    }

}

ll lca(ll u,ll v,ll mmax,vector<ll>&levels,vector<vector<ll>>&dp){
    if(levels[v]<levels[u]){
        ll t=u;
        u=v;
        v=t;
    }
    ll level_diff=levels[v]-levels[u];
    
    for(ll i=mmax;i>=0;i--){
        if(level_diff>=(1<<i)){
            v=dp[i][v];
            level_diff=level_diff-(1<<i);
        }
    }
    if(u==v){
        return u;
    }
    for(ll i=mmax;i>=0;i--){
        if(dp[i][u] != dp[i][v]){
            u=dp[i][u];
            v=dp[i][v];
        }
    }
    return dp[0][u];
}

ll mydfs(ll curr,ll p,vector<vector<ll>>&tree,vector<ll>& diffArray){
    ll val=diffArray[curr];
    for(ll i=0;i<tree[curr].size();i++){
        ll child=tree[curr][i];
        if(child != p){
            val=val+mydfs(child,curr,tree,diffArray);
        }
    }
    diffArray[curr]=val;
    return val;
}




void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll>parent(n+1);
    vector<vector<ll>>tree(n+1);
    for(ll i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<ll>levels(n+1,0);
    dfs(tree,1,1,levels,0,parent);
    ll mmax=18;
    vector<pair<ll,ll>>paths(m);
   
    vector<vector<ll>>dp(mmax+1,vector<ll>(n+1));
    build_anses_dp(parent,dp,n);
    vector<ll>diffArray(n+1,0);
     for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        paths[i].first=a;
        paths[i].second=b;
        diffArray[a]+=1;
        diffArray[b]+=1;
        ll x=lca(a,b,mmax,levels,dp);
        diffArray[x]-=1;
        if(x != 1){
            diffArray[parent[x]]-=1;    
        }

    }
    mydfs(1,1,tree,diffArray);
    for(ll i=1;i<=n;i++){
        cout<<diffArray[i]<<" ";
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

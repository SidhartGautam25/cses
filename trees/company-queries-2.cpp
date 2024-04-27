#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod LLONG_MAX
 
void dfs(vector<vector<ll>>&tree,ll curr,vector<ll>&levels,ll l,vector<ll>&parent){
    levels[curr]=l;
    for(ll i=0;i<tree[curr].size();i++){
        ll child=tree[curr][i];
        if(child != parent[curr]){
            dfs(tree,child,levels,l+1,parent);
        }
    }

}
 
void build_anses_dp(vector<ll>&parent,vector<vector<ll>>&dp,ll n){
    // ll n=parent.size();
    ll mmax=20;//this number is dur to the case that with 17,we can calculate for any given k upto 10^5
    for(ll i=1;i<=n;i++){
        dp[0][i]=parent[i];
    }
    for(ll i=1;i<mmax;i++){
        for(ll j=1;j<=n;j++){
            // let say we have to find 8th ansestor,then first we find 4th ansestor,and then again 4th ansestor
            // of the 4th ansestor
            //let say we call 4th ansestor anses1
            //then anses1 will be
            ll anses1=dp[i-1][j];//this is because ith box of j is storing 2^i th ansestor,
            // so 8th ansestor means 2^3,means i equal to 3,then 4th ansestor means 2^2,
            // means i-1,3-1 =2,thats why anses1 is equal to dp[i-1][j]

            // now lets say 8th ansestor be anses2,then anses2 will be 4th ansestor of anses 1;
            // so anses2 will be 
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
    // cout<<"level diff is "<<level_diff<<endl;
    // cout<<"u "<<u<<" v "<<v<<endl;
    for(ll i=mmax;i>=0;i--){
        if(level_diff>=pow(2,i)){
            v=dp[i][v];
            level_diff=level_diff-pow(2,i);
        }
    }
    // cout<<"u "<<u<<" v "<<v<<endl;
    if(u==v){
        return u;
    }
    for(ll i=mmax;i>=0;i--){
        if(dp[i][u] != dp[i][v]){
            // cout<<"for i "<<i<<" there parent is diffrent"<<endl;
            // cout<<"2^i parent of u "<<u<<" "<<dp[i][u]<<endl;
            // cout<<"2^i parent of v "<<v<<" "<<dp[i][v]<<endl;
            u=dp[i][u];
            v=dp[i][v];
        }
    }
    return dp[0][u];
}





void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll>parent(n+1);
    parent[1]=1;
    for(ll i=2;i<=n;i++){
        ll p;
        cin>>p;
        parent[i]=p;
    }
    vector<vector<ll>>tree(n+1);
    for(ll i=2;i<=n;i++){
        ll u=i;
        ll v=parent[i];
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<"parent is "<<i<<endl;
    //     for(int j=0;j<tree[i].size();j++){
    //         int child=tree[i][j];
    //         if(child != parent[i]){
    //             cout<<child<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }
    vector<ll>levels(n+1,0);
    dfs(tree,1,levels,0,parent);
    // for(int i=1;i<=n;i++){
    //     cout<<"level of i "<<i<<" is "<<levels[i]<<endl;
    // }
    ll mmax=20;
    vector<pair<ll,ll>>query(q);
    for(ll i=0;i<q;i++){
        ll a,b;
        cin>>a>>b;
        query[i].first=a;
        query[i].second=b;
    }
    vector<vector<ll>>dp(mmax+1,vector<ll>(n+1));
    build_anses_dp(parent,dp,n);
    for(ll i=0;i<q;i++){
        ll u=query[i].first;
        ll v=query[i].second;
        ll ans=lca(u,v,20,levels,dp);
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

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod LLONG_MAX
 
void dfs(vector<vector<int>>&tree,int curr,int p,vector<int>&levels,int l,vector<int>&parent){
    levels[curr]=l;
    parent[curr]=p;
    for(int i=0;i<tree[curr].size();i++){
        int child=tree[curr][i];
        if(child != p){
            dfs(tree,child,curr,levels,l+1,parent);
        }
    }

}
 
void build_anses_dp(vector<int>&parent,vector<vector<int>>&dp,int n){
    int mmax=18;
    for(int i=1;i<=n;i++){
        dp[0][i]=parent[i];
    }
    for(int i=1;i<mmax;i++){
        for(int j=1;j<=n;j++){
            int anses1=dp[i-1][j];
            int anses2=dp[i-1][anses1];
            dp[i][j]=anses2;
        }
    }

}

int lca(int u,int v,int mmax,vector<int>&levels,vector<vector<int>>&dp){
    if(levels[v]<levels[u]){
        int t=u;
        u=v;
        v=t;
    }
    int level_diff=levels[v]-levels[u];
    
    for(int i=mmax;i>=0;i--){
        if(level_diff>=(1<<i)){
            v=dp[i][v];
            level_diff=level_diff-(1<<i);
        }
    }
    if(u==v){
        return u;
    }
    for(int i=mmax;i>=0;i--){
        if(dp[i][u] != dp[i][v]){
            u=dp[i][u];
            v=dp[i][v];
        }
    }
    return dp[0][u];
}





void solve(){
    int n,q;
    cin>>n>>q;
    vector<int>parent(n+1);
    vector<vector<int>>tree(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int>levels(n+1,0);
    dfs(tree,1,1,levels,0,parent);
    int mmax=18;
    vector<pair<int,int>>query(q);
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        query[i].first=a;
        query[i].second=b;
    }
    vector<vector<int>>dp(mmax+1,vector<int>(n+1));
    build_anses_dp(parent,dp,n);
    for(int i=0;i<q;i++){
        int u=query[i].first;
        int v=query[i].second;
        if(u==1 || v==1){
            int ans=abs(levels[u]-levels[v]);
            cout<<ans<<endl;
        }else{
             int a=lca(u,v,18,levels,dp);
        int ans=levels[u]+levels[v]-2*levels[a];
        cout<<ans<<endl;

        }
       
    }
}


int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}

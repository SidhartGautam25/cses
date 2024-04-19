#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod LLONG_MAX
 
 
 
ll power(ll x, ll y)
{
    ll temp;
    if (y == 0){
        ll ans=1;
        return ans;
 
    }
       
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return ((temp%mod) * (temp%mod))%mod;
    else{
        ll p1=((x%mod)*(temp%mod))%mod;
        ll p2=((p1%mod)*(temp%mod))%mod;
        return p2;
    }
        
}
 
 
void dfs(vector<vector<int>>&tree,int curr,int& d,int dis,int p,int& node){
    if(dis>d){
        d=dis;
        node=curr;
    }
    
    for(int i=0;i<tree[curr].size();i++){
        int child=tree[curr][i];
        if(child != p){
            dfs(tree,child,d,dis+1,curr,node);
        }
    }
 
}
 
 
 
 
 
 
 
void solve(){
    int n;
    cin>>n;
    vector<vector<int>>tree(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int d=0;
    int curr=1;
    int dis=0;
    int p=1;
    int node=1;
    dfs(tree,curr,d,dis,p,node);
    //cout<<"d "<<d<<" node "<<node<<endl;
    dfs(tree,node,d,dis,node,node);
    cout<<d<<endl;
    
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
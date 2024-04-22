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
 
 void dfs(vector<vector<ll>>&tree,ll curr,ll p,vector<ll>&in,vector<ll>&count){
     ll sum=0;
    //  if(curr==1){
    //      cout<<"size is "<<tree[curr].size()<<endl;
    //      cout<<"p of 1 "<<p<<" and "<<tree[curr][0]<<endl;
    //  }
    for(ll i=0;i<tree[curr].size();i++){
        ll child=tree[curr][i];
        
        if(child != p){
            dfs(tree,child,curr,in,count);
            sum=sum+in[child]+count[child]+1;
            count[curr]=count[curr]+count[child]+1;
        }
    }
    //cout<<"for "<<curr<<" sum is "<<sum<<endl;
    in[curr]=sum;
 }

 void dfs2(vector<vector<ll>>&tree,ll curr,ll p,vector<ll>&in,vector<ll>&out,ll c,vector<ll>&count){
    for(ll i=0;i<tree[curr].size();i++){
        ll child=tree[curr][i];
        if(child != p){
            out[child]=in[curr]+out[curr]-in[child]+c-2*count[child]-2;
            dfs2(tree,child,curr,in,out,c,count);
        }
    }
 }

 
void solve(){
   ll n;
   cin>>n;
   vector<vector<ll>>tree(n);
   for(ll i=1;i<n;i++){
     ll u,v;
     cin>>u>>v;
     u--;
     v--;
     tree[u].push_back(v);
     tree[v].push_back(u);
   }
   vector<ll>count(n,0);
   vector<ll>in(n,0);
   vector<ll>out(n,0);
   dfs(tree,0,0,in,count);
   dfs2(tree,0,0,in,out,n,count);
   for(ll i=0;i<n;i++){
    ll ans=in[i]+out[i];
     cout<<ans<<endl;
   }

  
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
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
 
 
 
 
void dfs1(vector<vector<int>>&tree,int curr,int p,vector<int>&dp){
    dp[curr]=0;
    int mmax=0;
    for(int i=0;i<tree[curr].size();i++){
        int child=tree[curr][i];
        if(child != p){
            dfs1(tree,child,curr,dp);
            mmax=max(mmax,dp[child]+1);
        }
    }
    dp[curr]=mmax;
}

void dfs(vector<vector<int>>&tree,int curr,int p,vector<int>&in,vector<int>&out){
    int max_dis_1=-1;
    int max_dis_2=-1;
    for(int i=0;i<tree[curr].size();i++){
        int child=tree[curr][i];
        if(child != p){
            if(max_dis_1<in[child]){
                max_dis_2=max_dis_1;
                max_dis_1=in[child];
            }else if(max_dis_2<in[child]){
                max_dis_2=in[child];
            }

        }
    }

    for(int i=0;i<tree[curr].size();i++){
        int child=tree[curr][i];
        if(child != p){
            int max_dis=max_dis_1;
            if(max_dis==in[child]){
                max_dis=max_dis_2;
            }
            out[child]=1+max(out[curr],1+max_dis);
            dfs(tree,child,curr,in,out);
        }
    }
}
 
 
void solve(){
  
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
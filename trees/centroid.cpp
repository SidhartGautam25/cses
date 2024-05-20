#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod LLONG_MAX

int n;

int dfs(vector<vector<int>>&tree,int curr,int p,vector<int>&subtree,int&centroid){
    int total=1;
    bool poss=true;
    //cout<<"rec"<<endl;
    for(int i=0;i<tree[curr].size();i++){
        int child=tree[curr][i];
        if(child != p){
            int count=dfs(tree,child,curr,subtree,centroid);
            if(count>(n/2)){
                poss=false;
            }
            total=total+count;
        }
    }
    if(poss){
        int rem=n-total;
        if(rem<=(n/2)){
            centroid=curr;
        }
    }
    subtree[curr]=total;
    return total;
}


void solve(){
  
    cin>>n;
    vector<vector<int>>tree(n+1);

    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int centroid=1;
    vector<int>subtree(n+1);

    dfs(tree,1,1,subtree,centroid);
   // cout<<"hello"<<endl;
    cout<<centroid<<endl;


    
   
}


int main(){
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}

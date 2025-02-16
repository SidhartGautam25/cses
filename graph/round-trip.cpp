#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod LLONG_MAX

void FIND_PATH(vector<vector<int>>&g,int curr,int p,int ans,vector<int>&vis,vector<int>&path){
    if(curr==ans and path.size()>0){
        return;
    }
    path.push_back(curr);
    for(int i=0;i<g[curr].size();i++){
        int child=g[curr][i];
        if(child != p){
            FIND_PATH()
        }
    }
}

void dfs(vector<vector<int>>&g,int curr,int p){

    if(vis[curr]){
        ans=curr;
    }
    vis[curr]=true;
    

    for(int i=0;i<g[curr].size();i++){
        int child=g[curr][i];
        if(child != p){
            dfs(g,child,curr);
        }
    }
}

void solve(){
  
  int n,m;
  cin>>n>>m;
  vector<vector<int>>graph(n+1);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int ans=-1;
  vector<bool>vis(n+1,false);
  dfs(graph,1,1,ans);

  if(ans == -1){
    cout<<"IMPOSSIBLE"<<endl;
    return;
  }

  vector<int>path;
  for(int i=0;i,=n;i++){
    vis[i]=false;
  }
  FIND_PATH(graph,ans,ans,ans,vis,path);

  for(int i=0;i<path.size();i++){
     cout<<path[i]<<"  ";
  }
  cout<<ans<<endl;

    
   
}


int main(){
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}

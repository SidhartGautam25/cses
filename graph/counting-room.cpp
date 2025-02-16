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
  
  int n,m;
  cin>>n>>m;
  vector<vector<char>>map(n,vector<char>(m));
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>map[i][j];
    }
  }
  

    
   
}


int main(){
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}

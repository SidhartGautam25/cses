#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod LLONG_MAX

set<int> *ms[200001];

void dfs(int curr,int p,vector<vector<int>>&tree,vector<int>&colors,vector<int>&ans){
    int max_set_size=0;
    int maxSizeNode=-1;
    //cout<<"here 1 "<<curr<<endl;
    for(int i=0;i<tree[curr].size();i++){
        int child=tree[curr][i];
        if(child != p){
            dfs(child,curr,tree,colors,ans);
            if(max_set_size<ms[child]->size()){
                max_set_size=ms[child]->size();
                maxSizeNode=child;
            }
        }
    }

    if(maxSizeNode == -1) ms[curr] = new set<int>();
	else			 ms[curr] = ms[maxSizeNode];



    
    ms[curr]->insert(colors[curr]);
    for(int i=0;i<tree[curr].size();i++){
        int child=tree[curr][i];
        if((child != p) && (child != maxSizeNode)){
            for(auto it:*ms[child]){
                ms[curr]->insert(it);
            }
            
        }
    }
   
    ans[curr]=ms[curr]->size();
}
 

void solve(){
    int n;
    cin>>n;
    vector<vector<int>>tree(n+1);
    //vector<set<int>>ms(n+1);
    vector<int>colors(n+1);
    for(int i=1;i<=n;i++){
        cin>>colors[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int>ans(n+1,0);
    dfs(1,1,tree,colors,ans);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }

    


    
   
}


int main(){
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}

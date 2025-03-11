#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod ll_MAX


void dfs(vector<vector<ll>>&roads,vector<bool>&visited,ll i){
    if(visited[i]){
        return;
    }

    visited[i]=true;

    for(ll x=0;x<roads[i].size();x++){
        ll c=roads[i][x];
        dfs(roads,visited,c);
    }
}



void solutionOne(){


    ll n,m;
    cin>>n>>m;


    vector<bool>visited(n+1,false);
    vector<ll>cities;

    vector<vector<ll>>roads(n+1);

    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        roads[x].push_back(y);
        roads[y].push_back(x);
    }

    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            cities.push_back(i);
            dfs(roads,visited,i);
        }
    }
    

    ll ans=cities.size()-1;
    cout<<ans<<endl;
    for(ll i=1;i<cities.size();i++){
        cout<<cities[i-1]<<" "<<cities[i]<<endl;
    }




    
    

  




}

int main(){

    solutionOne();

    return 0;
}
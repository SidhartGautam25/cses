#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod LLONG_MAX
 
void dfs(vector<vector<ll>>&tree,ll curr,ll p,vector<ll>&start,vector<ll>&end,vector<ll>&map,vector<ll>&value,ll& time){
    start[curr]=time;
    map[time]=value[curr];
    time++;
    for(ll i=0;i<tree[curr].size();i++){
        ll child=tree[curr][i];
        if(child != p){
            dfs(tree,child,curr,start,end,map,value,time);
        }
    }
    end[curr]=time;
    map[time]=-value[curr];
    time++;
}
ll getSum(vector<ll>&BTree,ll i){
    ll sum=0;
    while(i>0){
        sum=sum+BTree[i];
        i=i-(i&(-i));
    }
    return sum;
}

void addBTree(vector<ll>&BTree,ll i,ll val){
    ll n=BTree.size();
    while(i<n){
        BTree[i]+=val;
        i=i+(i&(-i));
    }
}

void buildBTree(vector<ll>&BTree,vector<ll>&map,ll& time){
    for(ll i=1;i<time;i++){
        addBTree(BTree,i,map[i]);
    }
}

void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll>value(n+1);
    for(ll i=1;i<=n;i++){
        cin>>value[i];
    }
    vector<vector<ll>>tree(n+1);
    for(ll i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }


    vector<ll>start(n+1);
    vector<ll>end(n+1);
    vector<ll>map(2*n+10);
    vector<ll>BTree(map.size(),0);

    ll time=1;
    dfs(tree,1,1,start,end,map,value,time);
    buildBTree(BTree,map,time);
    // cout<<"map is "<<endl;
    // for(int i=0;i<map.size();i++){
    //     cout<<map[i]<<"  ";
    // }
    // cout<<endl;


    for(ll i=0;i<q;i++){
        ll type;
        cin>>type;
        if(type==1){
            ll v,val;
            cin>>v>>val;
            ll diff1=val-value[v];
            ll diff2=-diff1;
            value[v]=val;
            map[start[v]]=val;
            map[end[v]]=-val;
            addBTree(BTree,start[v],diff1);
            addBTree(BTree,end[v],diff2);


        }else{
            ll v;
            cin>>v;
            ll ans=getSum(BTree,start[v])-getSum(BTree,start[1]-1);
            cout<<ans<<endl;

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

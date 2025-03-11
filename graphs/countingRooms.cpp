#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX


bool safe(int n,int m,int i,int j){
    if(i>=0 && i<n){
        if(j>=0 && j<m){
            return true;
        }
    }

    return false;
}


void dfs(vector<vector<int>>& graph,int n,int m,int i,int j){
    if(!safe(n,m,i,j)){
        return;
    }

    if(graph[i][j]==1){
        return;
    }

    graph[i][j]=1;

    vector<pair<int,int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
    int four=4;

    for(int k=0;k<four;k++){
        int ii=i+directions[k].first;
        int jj=j+directions[k].second;
        dfs(graph,n,m,ii,jj);
    }
}




void solutionOne(){
    

  int n,m;
  cin>>n>>m;

  vector<vector<int>>flat(n,vector<int>(m,0));

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        char c;
        cin>>c;
        if(c=='#'){
            flat[i][j]=1;
        }
    }
  }


  int count=0;
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(flat[i][j]==0){
            count++;
            dfs(flat,n,m,i,j);
        }
    }
  }




  cout<<count<<endl;




}

int main(){

    solutionOne();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007


void recursiveSolve(vector<int>&coins,int curr,vector<int>&ans,map<int,int>&mp){
    if(curr==coins.size()){
        return;
    }
    if(curr==0){
        ans.push_back(coins[curr]);
        ans.push_back(0);
        mp[coins[curr]]=true;
        mp[0]=false;
        recursiveSolve(coins,curr+1,ans,mp);
        return;
    }
    int n=ans.size();
    for(int i=0;i<n;i++){
        ans.push_back(ans[i]+coins[curr]);
        mp[ans[i]+coins[curr]]=true;
    }
    recursiveSolve(coins,curr+1,ans,mp);




}

// recursive solution
// tle
void solutionOne() {

    int n;
    cin>>n;
    vector<int>coins(n);
    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<int>ans;
    int curr=0;
    recursiveSolve(coins,curr,ans,mp);


    int s=mp.size()-1;
    cout<<s<<endl;
    
    for(auto it:mp){
        if(it.second==true){
            cout<<it.first<<" ";
            it.second=false;
        }
    }
    
  
}


// bit manupulation approach
// tle solution
void solutionTwo(){
    int n;
    cin>>n;
    vector<int>coins(n);
    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    ll total=1<<n;
    // cout<<total<<endl;

    for(int i=1;i<=total;i++){
        int amount=0;
        for(int j=0;j<coins.size();j++){
            if((1<<j)&i){
                // cout<<"for i "<<i<<" j "<<j<<endl;
                amount=amount+coins[j];
            }
        }
        mp[amount]=true;
    }

    mp[0]=false;
    int s=mp.size()-1;
    cout<<s<<endl;
    for(auto it:mp){
        if(it.second){
            cout<<it.first<<" ";
            it.second=false;
        }
    }

}


// dp solution
void solutionThree(){

}





int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solutionTwo();

    return 0;
}

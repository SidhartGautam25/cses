#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007


void read_iv(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void print_iv(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void read_i(int& x){
    cin>>x;
}


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
// feasible
void solutionThree(){

    int n;
    read_i(n);
   
    vector<int>coins(n);
    read_iv(coins);

    

    int max_sum=1e5;
    vector<vector<bool>>dp(n+1,vector<bool>(max_sum,false));

    // dp[i][j]
    // is it possible to make sum j with i coins

    dp[0][0]=true;

    for(int i=1;i<=n;i++){
        for(int curr_sum=0;curr_sum<=max_sum;curr_sum++){
            dp[i][curr_sum]=dp[i-1][curr_sum];
            int prev_sum=curr_sum-coins[i-1];
            if(prev_sum>=0){
                dp[i][curr_sum]=dp[i][curr_sum] || dp[i-1][prev_sum];
            }
        }
    }

    vector<int>sums;
    for(int curr_sum=1;curr_sum<=max_sum;curr_sum++){
        if(dp[n][curr_sum]){
            sums.push_back(curr_sum);
        }

    }

    cout<<sums.size()<<endl;
    print_iv(sums);
    

}





int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solutionThree();

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

int solve(string first,int n,string second,int m,int i,int j){

    if(i>=n || j>=m){
        if(i==n){
            return m-j;
        }
        return n-i;
    }

    if(first[i]==second[j]){
        return solve(first,n,second,m,i+1,j+1);
    }else{
        // Insertion on first string
        int insAns=solve(first,n,second,m,i,j+1)+1;
        // Deletion on first string
        int delAns=solve(first,n,second,m,i+1,j)+1;
        // Replacement operation on first string
        int repAns=solve(first,n,second,m,i+1,j+1)+1;

        return min(insAns,min(delAns,repAns));
    }
}

int memoizedSolve(vector<vector<int>>&dp,string first,int n,string second,int m,int i,int j){

    if(i>=n || j>=m){
        if(i==n){
            return m-j;
        }
        return n-i;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(first[i]==second[j]){
        int output= solve(first,n,second,m,i+1,j+1);
        dp[i][j]=output;
        return output;
    }else{
        // Insertion on first string
        int insAns=solve(first,n,second,m,i,j+1)+1;
        // Deletion on first string
        int delAns=solve(first,n,second,m,i+1,j)+1;
        // Replacement operation on first string
        int repAns=solve(first,n,second,m,i+1,j+1)+1;

        int ans= min(insAns,min(delAns,repAns));
        dp[i][j]=ans;
        return ans;
    }
}

// recursive code
void solutionTwo(){
    string first;
    string second;

    cin>>first;
    cin>>second;

    int n=first.size();
    int m=second.size();

    // we can do three operation
    // 1. Insertion
    // 2. Deletion
    // 3. Replacement

    // now one thing to note --> we will do operations on string first
    // to make it equal to second one

    int op=solve(first,n,second,m,0,0);

    cout<<op<<endl;

}

// memoized code
void solutionThree(){

    string first;
    string second;

    cin>>first;
    cin>>second;

    int n=first.size();
    int m=second.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    int op=memoizedSolve(dp,first,n,second,m,0,0);

    cout<<op<<endl;

}



void solutionOne(){
    string first;
    string second;

    cin>>first;
    cin>>second;

    int n=first.size();
    int m=second.size();

    vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
    dp[0][0]=0;

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
           
            }
        }
    }



   



int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    // solutionTwo();
    solutionThree();

    return 0;
}
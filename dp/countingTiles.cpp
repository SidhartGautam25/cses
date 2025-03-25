#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007



// j is the index of current row we are working on
void generateNextMask(ll n,ll curr_mask,ll new_mask,ll j,vector<ll>&nextMask){
    if(j==n){
        // first of all,we need to know that we are creating our mask 
        // for each column row by row.
        // means work on current row then go to next row
        // until we come to the last row
        // and when we come to the last row,its means we have 
        // computed our mask
        nextMask.push_back(new_mask);
        return;
    }

    // place a 2 X 1 tile
    // if case is just checking that j and j+1 row should be empty
     if (j + 1 < n && (((1 << j) & (curr_mask)) == 0) && (((1 << (j + 1)) & (curr_mask)) == 0))
    {
        generateNextMask(n,curr_mask,new_mask,j+2,nextMask);
        // new_mask has no effect of 2X1 tile as it is vertical

    }

    // place 1 X 2 tile
     if ((((1 << j) & (curr_mask)) == 0))
    {
        generateNextMask(n,curr_mask,new_mask+(1<<j),j+1,nextMask);
        // 1X2 tile fill the new_mask also as it affect the next column
    }
    // move to the next cell if current is already filled
     if ((((1 << j) & (curr_mask)) != 0))
    {
        generateNextMask(n,curr_mask,new_mask,j+1,nextMask);
    }


}
ll helperOne(ll n,ll m,ll col,ll mask,vector<vector<ll>>&dp){

    // base case
    if(col==m){
        if(mask==0){
            return 1;
        }
        return 0;
    }

    if(dp[col][mask] != -1){
        return dp[col][mask];
    }

    vector<ll>nextMask;
    ll new_mask=0;
    ll row=0;

    // for now,nextMask array contains diffrent possible mask for next column  
    // nextmask as you can see is independent of current column
    // because to generate next possible masks we only need current mask and 
    // the length of row
    generateNextMask(n,mask,new_mask,row,nextMask);

    ll ans=0;

    for(ll next:nextMask){

        // just adding ways to arranage tiles from next column to mth column 
        // for a specific mask 
        ll t=helperOne(n,m,col+1,next,dp);
        ans=((ans%mod)+(t%mod))%mod;
    }


    dp[col][mask]=ans;
    return ans;



}

void solutionOne(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>dp(m+1,vector<ll>(1<<n,-1));
    ll ans=helperOne(n,m,0,0,dp);
    cout<<ans<<endl;

    

}
   
   

   



int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    // solutionTwo();
    // solutionThree();
    solutionOne();

    return 0;
}
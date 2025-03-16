#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007


void solutionOne() {
    int x,y;
    cin>>x>>y;

    vector<vector<int>>dp(x+1,vector<int>(y+1,INT_MAX));

    for(int i=1;i<=x;i++){
        dp[i][0]=i;

    }

    for(int i=1;i<=y;i++){
        dp[0][i]=i;

    }
    dp[0][0]=0;

    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(i==j){
                dp[i][j]=0;

            }else{
                // vertical cutting
                // in vertical cutting j remain constant 
                // and k will vary from k=1 to k=x-1 ( if observed here,we can save 
                // so much time and computation,but leave for future)
                for(int k=1;k<i;k++){
                    dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
                }
                // horizontal cutting
                for(int k=1;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
                }

            }
        }
    }

    cout<<dp[x][y]<<endl;


   




}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solutionOne();

    return 0;
}

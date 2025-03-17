#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007



// tle solution
void solutionOne(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int>dp(n,1);
    dp[0]=1;
    int ans=1;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;



}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    solutionOne();

    return 0;
}
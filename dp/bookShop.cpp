#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

// working solution
// using 1D dp array
void solutionOne() {
    int n, x;
    cin >> n >> x;

    vector<int> books(n);
    vector<int> pages(n);
    for (int i = 0; i < n; i++) cin >> books[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    vector<int> dp(x + 1, 0);

    for (int j = 0; j < n; j++) {
        // Reverse iterate to prevent multiple use of the same book
        for (int i = x; i >= books[j]; i--) {
            dp[i] = max(dp[i], dp[i - books[j]] + pages[j]);
        }
    }

    cout << dp[x] << endl;
}


// using 2D dp array
void solutionTwo(){
     int n,x;
    cin>>n>>x;
    vector<int>books(n);
    for(int i=0;i<n;i++){
        cin>>books[i];
    }
    vector<int>pages(n);
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
 
    vector<vector<int>>dp(x+1,vector<int>(n+1));
    for(int i=1;i<=x;i++){
        for(int j=1;j<=n;j++){
            if(i-books[j-1]>=0){
                   dp[i][j]=max(dp[i][j-1],dp[i-books[j-1]][j-1]+pages[j-1]);
            }else{
                   dp[i][j]=dp[i][j-1];
            }
            
        }
    }
 
    cout<<dp[x][n]<<endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solutionOne();

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007



void solutionOne(){

 int n,m;
 cin>>n>>m;
 vector<int>arr(n);
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 vector<vector<int>> dp(n, vector<int>(m + 1, 0));
 if (arr[0] == 0) { // Free to choose any value from 1 to m
        for (int x = 1; x <= m; x++) {
            dp[0][x] = 1;
        }
    } else { // Fixed value
        dp[0][arr[0]] = 1;
    }

 // Fill DP Table
    for (int i = 1; i < n; i++) {
        if (arr[i] == 0) { // Free to choose any value
            for (int x = 1; x <= m; x++) {
                dp[i][x] = dp[i - 1][x]; // Coming from same value
                if (x > 1) dp[i][x] = (dp[i][x] + dp[i - 1][x - 1]) % MOD; // Coming from x-1
                if (x < m) dp[i][x] = (dp[i][x] + dp[i - 1][x + 1]) % MOD; // Coming from x+1
            }
        } else { // Fixed value
            int x = arr[i];
            dp[i][x] = dp[i - 1][x];
            if (x > 1) dp[i][x] = (dp[i][x] + dp[i - 1][x - 1]) % MOD;
            if (x < m) dp[i][x] = (dp[i][x] + dp[i - 1][x + 1]) % MOD;
        }
    }

    int result = 0;
    for (int x = 1; x <= m; x++) {
        result = (result + dp[n - 1][x]) % MOD;
    }

    cout << result << endl;
 

}

// reduces space complexity
void solutionTwo(){
      int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    if (arr[0] == 0) {
        for (int x = 1; x <= m; x++) prev[x] = 1;
    } else {
        prev[arr[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        fill(curr.begin(), curr.end(), 0);
        if (arr[i] == 0) {
            for (int x = 1; x <= m; x++) {
                curr[x] = prev[x];
                if (x > 1) curr[x] = (curr[x] + prev[x - 1]) % MOD;
                if (x < m) curr[x] = (curr[x] + prev[x + 1]) % MOD;
            }
        } else {
            int x = arr[i];
            curr[x] = prev[x];
            if (x > 1) curr[x] = (curr[x] + prev[x - 1]) % MOD;
            if (x < m) curr[x] = (curr[x] + prev[x + 1]) % MOD;
        }
        swap(prev, curr);
    }

    int result = 0;
    for (int x = 1; x <= m; x++) {
        result = (result + prev[x]) % MOD;
    }

    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    solutionTwo();

    return 0;
}
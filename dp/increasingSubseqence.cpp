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


void solutionTwo(){
      int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> sub; // Stores the smallest tail values of LIS of different lengths

    for (int num : arr) {
        auto it = lower_bound(sub.begin(), sub.end(), num);
        if (it == sub.end()) {
            sub.push_back(num); // Extend LIS
        } else {
            *it = num; // Replace existing element to maintain optimal subsequence
        }
    }

    cout << sub.size() << endl; // Length of LIS
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    solutionTwo();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define INF 1e9


void solutionOneHelper(int ind,int n,vector<int>&rides,vector<int>&rideWeight,int& minRides,vector<int>&w,int x){
    if(ind==n){
        minRides=min(minRides,(int)rides.size());
        return;
    }

    // first we will try to fit the current person in an existing elevator
    for(int i=0;i<rides.size();i++){
        if(rideWeight[i]+w[ind]<=x){
            rideWeight[i]=rideWeight[i]+w[ind];// addeed the current one to this 
            solutionOneHelper(ind+1,n,rides,rideWeight,minRides,w,x);
            rideWeight[i]=rideWeight[i]-w[ind];// backtrack
        }
    }

    // now try a new ride
    rides.push_back(ind);
    rideWeight.push_back(w[ind]);
    solutionOneHelper(ind+1,n,rides,rideWeight,minRides,w,x);
    rides.pop_back();
    rideWeight.pop_back();
}


// TLE Solution
// but a good one to understand this problem
// time complexity is O(2^n)

// what we are doing in this solution is trying to find every possible solution 
// and then choose the best one
// recursive approach
void solutionOne() {
   int n,x;
   cin>>n>>x;
   vector<int>w(n);
   for(int i=0;i<n;i++){
       cin>>w[i];
   }
   vector<int>rides;
   vector<int>rideWeight;
   int minRides=n;
   int ind=0;
   solutionOneHelper(ind,n,rides,rideWeight,minRides,w,x);
   cout<<minRides<<endl;



}

// acceptable solution
// known as bitmask dp
void solutionTwo(){

   int n,x;
   cin>>n>>x;
   vector<int>w(n);
   for(int i=0;i<n;i++){
       cin>>w[i];
   }

    // Let dp[mask] represent the minimum number of elevator rides needed to transport 
    // the subset of people represented by mask.

    // dp[mask] = {minimum rides, current weight in last ride}
    vector<pair<int, int>> dp(1 << n, {INF, 0});
    dp[0] = {1, 0}; // Base case: 1 ride needed, 0 weight

      for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue; // Skip if person i is already in mask

            int new_mask = mask | (1 << i); // Add person i to mask
            auto [rides, lastWeight] = dp[mask];

            if (lastWeight + w[i] <= x) {
                // Person i fits in the current ride
                dp[new_mask] = min(dp[new_mask], {rides, lastWeight + w[i]});
            } else {
                // Need a new ride
                dp[new_mask] = min(dp[new_mask], {rides + 1, w[i]});
            }
        }
    }

    cout << dp[(1 << n) - 1].first << endl; // Answer for all people

}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solutionTwo();

    return 0;
}

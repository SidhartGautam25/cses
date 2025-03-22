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
// need to solve more question on bitmask dp
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


bool canFit(int k,int x,vector<int>&w){
    multiset<int>rides;
    for(int i=0;i<k;i++){
        rides.insert(x);
    }

    for(int i=0;i<w.size();i++){
        int ww=w[i];
        // auto it=rides.lower_bound(ww);
        auto it = rides.upper_bound(ww - 1); // Find the tightest fitting ride

        if(it==rides.end()){
            // no space availabe
            return false;
        }

        int remaining=*it-ww;
        rides.erase(it);
        rides.insert(remaining);
    }

    return true;

}



















// First-Fit Decreasing (FFD) Heuristic + Binary Search.
// have some issues( will figure it out)
// using multi set 
void solutionThree(){
    // inspired by bin packing problems, where we try to fit items (people) into bins
    // (elevator rides) efficiently.

    int n,x;
    cin>>n>>x;
    vector<int>w(n);
    for(int i=0;i<n;i++){
        cin>>w[i];
    }

    sort(w.rbegin(),w.rend());
    int left=1;
    int right=n;
    int ans=n;

    while(left<=right){
        int mid=(left+right)/2;
        if(canFit(mid,x,w)){
            ans=mid;
            right=mid-1; // try fewer rides
        }else{
            left=mid+1; // need more rides
        }

    }

    cout << ans << endl;



}






bool greedyCanFit(int k,vector<int>&weight,int x){
    int rides=0;
    int left=0;
    int n=weight.size();
    int right=n-1;

    while(left<=right){
        if(left==right){
            rides++;
            break;
        }
        if(weight[left]+weight[right]<=x){
            left++;
        }
        right--;
        rides++;
        if(rides>k){
            return false;
        }
    }

    return rides<=k;

}




// same concept of solutionThree 
// but without using multiset
void solutionFour(){

    int n,x;
    cin>>n>>x;
    vector<int>weight(n);
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }

    sort(weight.begin(),weight.end());

    int left=1;
    int right=n;
    int ans=n;

    while(left<=right){
        int mid=(left+right)/2;
        if(greedyCanFit(mid,weight,x)){
            ans=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }

    cout<<ans<<endl;

}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solutionFour();

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007


struct Project {
    ll start, end, reward;
};



void read_iv(vector<ll>&arr){
    ll n=arr.size();
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
}

void read_ipv(vector<pair<ll,ll>>& arr){
    ll n=arr.size();
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        arr[i].first=x;
        arr[i].second=y;
    }
}

void prll_iv(vector<ll>&arr){
    ll n=arr.size();
    for(ll i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void read_i(ll& x){
    cin>>x;
}



ll latestNonOverlapping(vector<Project>& projects, vector<ll>& endTimes, ll start_time) {
    ll left = 0, right = projects.size() - 1, pos = -1;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (endTimes[mid] < start_time) {
            pos = mid; // Possible candidate
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return pos; // Returns index of the last valid non-overlapping project
}




void solutionOne() {
    ll n;
    read_i(n);
    vector<Project>projects(n);
    vector<ll>endTimes(n);
    for(ll i=0;i<n;i++){
        ll start,end,reward;
        cin>>start>>end>>reward;
        projects[i].start=start;
        projects[i].end=end;
        projects[i].reward=reward;
    }

    
    sort(projects.begin(), projects.end(), [](const Project &a, const Project &b) {
        return a.end < b.end;
    });

    for(ll i=0;i<n;i++){
        endTimes[i]=projects[i].end;
    }

     vector<ll> dp(n); 

     for (ll i = 0; i < n; i++) {
        ll include = projects[i].reward;
        ll lastNonOverlap = latestNonOverlapping(projects, endTimes, projects[i].start);
        if (lastNonOverlap != -1) {
            include += dp[lastNonOverlap]; // Add max reward up to lastNonOverlap
        }
        
        ll exclude = (i > 0) ? dp[i - 1] : 0; // Skip current project
        
        dp[i] = max(include, exclude); // Store max reward at index i
    }

    cout<<dp[n-1]<<endl;





  
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solutionOne();

    return 0;
}

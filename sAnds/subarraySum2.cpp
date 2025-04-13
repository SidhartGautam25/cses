#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007


void read_iv(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void read_lv(vector<ll>&arr){
    ll n=arr.size();
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void read_ipv(vector<pair<int,int>>& arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        arr[i].first=x;
        arr[i].second=y;
    }
}

void print_iv(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void read_i(int& x){
    cin>>x;
}

void read_l(ll& x){
    cin>>x;
}




void solutionOne() {


    ll n, x;
    cin >> n >> x;

    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    map<long long, ll> prefixCount;
    prefixCount[0] = 1; // Empty prefix sum

    long long sum = 0;
    ll count = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        count += prefixCount[sum - x];
        prefixCount[sum]++;
    }

    cout << count << endl;
    
  
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solutionOne();

    return 0;
}

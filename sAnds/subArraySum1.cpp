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


    int n,x;
    read_i(n);
    read_i(x);

    vector<int>arr(n);
    read_iv(arr);

    int i=0;
    int j=0;

    int t=0;
    int count=0;

    while( j<n){
       t += arr[j]; // expand the window to the right
       j++;

    // shrink the window from the left if sum > x
    while (t > x && i < j) {
        t -= arr[i];
        i++;
    }

    // Check if current sum equals x
    if (t == x) {
        count++;
    }
        
    }

    cout<<count<<endl;
  
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solutionOne();

    return 0;
}

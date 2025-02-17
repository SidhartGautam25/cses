
  #include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX




int main(){

    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    // we have two option

    // the first is,we can check the max frequency length
    // and then make all stick equal to that

    // now second option is,we can choose the mediun length
    // and then make all stick equal to them

    // best is second one

    sort(arr.begin(),arr.end());

    ll mediun=arr[n/2];
    ll ans=0;
    for(ll i=0;i<n;i++){
        ans=ans+abs(mediun-arr[i]);
    }

    cout<<ans<<endl;
    








}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX


int main(){
    ll n;
    cin>>n;
    map<ll,ll>mp;
    
    for(int i=0;i<n;i++){
        ll temp;
        cin>>temp;
        mp[temp]++;
    }

    cout<<mp.size()<<endl;

    return 0;
}
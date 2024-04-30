#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod LLONG_MAX

void solve(){
    ll x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    ll slope_diff=(x3-x2)*(y2-y1)-(x2-x1)*(y3-y2);
    if(slope_diff<0){
        cout<<"LEFT"<<endl;
    }else if(slope_diff>0){
        cout<<"RIGHT"<<endl;
    }else{
        cout<<"TOUCH"<<endl;
    }

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    
    cin>>t;
    while(t--){
        solve();
     }

    return 0;
}
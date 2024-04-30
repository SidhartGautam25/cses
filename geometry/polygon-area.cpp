#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod LLONG_MAX

ll direction(ll x1,ll x2,ll x3,ll y1,ll y2,ll y3){

    ll slope_diff=((((x3-x2)%mod)*((y2-y1)%mod))%mod)-((((x2-x1)%mod)*((y3-y2)%mod))%mod);
    if(slope_diff<0){
        return -1;
    }else if(slope_diff>0){
        return 1;
    }
    return 0;
}

bool onlineSegment(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){
    return( (x3<=max(x1,x2)) && (x3>=min(x1,x2)) &&  (y3<=max(y1,y2)) && (y3>=min(y1,y2)) );
}

void solve(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>>polls(n);
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        polls[i].first=x;
        polls[i].second=y;
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        ll x1=polls[i].first;
        ll y1=polls[i].second;
        ll x2=polls[(i+1)%n].first;
        ll y2=polls[(i+1)%n].second;
        ans=ans+((x1*y2)-(y1*x2));
    }
    cout<<abs(ans)<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t=1;
    
    //cin>>t;
    while(t--){
        solve();
     }

    return 0;
}
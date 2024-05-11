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
    ll x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    ll s1=direction(x1,x2,x3,y1,y2,y3);
    ll s2=direction(x1,x2,x4,y1,y2,y4);
    ll s3=direction(x3,x4,x1,y3,y4,y1);
    ll s4=direction(x3,x4,x2,y3,y4,y2);

    if((s1*s2<0) && (s3*s4<0)){
        cout<<"YES"<<endl;
        return;
    }
    if(s1==0 && onlineSegment(x1,y1,x2,y2,x3,y3)){
        cout<<"YES"<<endl;
        return;
    }else if(s2==0 && onlineSegment(x1,y1,x2,y2,x4,y4)){
        cout<<"YES"<<endl;
        return;
    }else if(s3==0 && onlineSegment(x3,y3,x4,y4,x1,y1)){
        cout<<"YES"<<endl;
        return;
    }else if(s4==0 && onlineSegment(x3,y3,x4,y4,x2,y2)){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;

    
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
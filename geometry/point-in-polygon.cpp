#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX

ll direction(ll x1,ll x2,ll x3,ll y1,ll y2,ll y3){

    ll slope_diff=((x3-x2)*(y2-y1))-((x2-x1)*(y3-y2));
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

bool intersect(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3,ll x4,ll y4){
    ll s1=direction(x1,x2,x3,y1,y2,y3);
    ll s2=direction(x1,x2,x4,y1,y2,y4);
    ll s3=direction(x3,x4,x1,y3,y4,y1);
    ll s4=direction(x3,x4,x2,y3,y4,y2);
    //cout<<"s1 "<<s1<<" s2 "<<s2<<" s3 "<<s3<<" s4 "<<s4<<endl;

    if((s1 != s2) && (s3 != s4)){
       // cout<<"intersect"<<endl;
        return true;
    }
    //cout<<"dont"<<endl;
    return false;
    
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>poly(n);
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        poly[i].first=x;
        poly[i].second=y;
    }
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        ll count=0;
        ll edge=0;
        bool boundary=false;
        for(ll i=0;i<n;i++){
            ll p1x=poly[i].first;
            ll p1y=poly[i].second;

            ll p2x=poly[(i+1)%n].first;
            ll p2y=poly[(i+1)%n].second;
 
            ll infx=(ll)INT_MAX;
            ll infy=(ll)INT_MAX+17;

            if(direction(p1x,p2x,x,p1y,p2y,y)==0 && onlineSegment(p1x,p1y,p2x,p2y,x,y)){
                boundary=true;
                break;
            }
            //cout<<"for line "<<i+1<<endl;
            if(intersect(p1x,p1y,p2x,p2y,x,y,infx,infy)){
                count++;
            }  
            // if(i==0){
            //     cout<<"line 1 "<<direction(x,infx,p1x,y,infy,p1y);
                
            // }
            
        }
        //cout<<"count "<<endl;
        if(boundary){
            cout<<"BOUNDARY"<<endl;
        }else if(count%2==1){
            cout<<"INSIDE"<<endl;
        }else{
            cout<<"OUTSIDE"<<endl;
        }  
    }
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
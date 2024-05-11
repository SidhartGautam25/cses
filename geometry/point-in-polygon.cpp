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

int check(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4){
    ll s1=direction(x1,x2,x3,y1,y2,y3);
    ll s2=direction(x1,x2,x4,y1,y2,y4);
    ll s3=direction(x3,x4,x1,y3,y4,y1);
    ll s4=direction(x3,x4,x2,y3,y4,y2);
    // cout<<s1<<" "<<s2<<" "<<s3<<"  "<<s4<<endl;
    // cout<<"online "<<onlineSegment(x1,y1,x2,y2,x3,y3)<<endl;


    if(s1==0 && onlineSegment(x1,y1,x2,y2,x3,y3)){
        //cout<<"come here"<<endl;
        return 2;
    }
    if(y3==y1 || y3==y2){
        if(x3<max(x1,x2)){
            return 3;
        }
    }
    if((s1 != s2) && (s3 != s4)){
        //cout<<"product "<<s1*s2<<"   "<<s3*s4<<endl;
        // if(y3==y1 || y3==y2){
        //     return 3;
        // }
        return 1;
    }
    if(s1==0 && onlineSegment(x1,y1,x2,y2,x3,y3)){
        //cout<<"come here"<<endl;
        return 2;
    }
    return 0;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>poly(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        poly[i].first=x;
        poly[i].second=y;
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        int count=0;
        int edge=0;
        for(int i=0;i<n;i++){
            int p1x=poly[i].first;
            int p1y=poly[i].second;

            int p2x=poly[(i+1)%n].first;
            int p2y=poly[(i+1)%n].second;
 
            int infx=INT_MAX;
            int infy=y;

            int res=check(p1x,p2x,x,infx,p1y,p2y,y,infy);
            cout<<"res "<<res<<endl;
            if(res==1){
                count++;
            }else if(res==2){
                count=-1;
                break;
            }else if(res==3){
                edge++;
            }
        }
        cout<<"count "<<count<<" edge "<<edge<<endl;
        count=count+(edge/2);
        if(count==-1){
            cout<<"BOUNDARY"<<endl;
        }else if(count%2==0){
            cout<<"OUTSIDE"<<endl;
        }else{
            cout<<"INSIDE"<<endl;
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
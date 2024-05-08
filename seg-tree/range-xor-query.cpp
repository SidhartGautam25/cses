#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod LLONG_MAX
 


void buildTree(vector<ll>& seg,vector<ll>&nums, ll pos, ll left, ll right){
        if (left == right){
            seg[pos] = nums[left];
            return;
        }
        ll mid = (left+right)/2;
        buildTree(seg,nums, 2*pos+1, left, mid);
        buildTree(seg,nums, 2*pos+2, mid+1, right);
        // seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
        seg[pos]=seg[2*pos+1]^seg[2*pos+2];
}



ll rangeUtil(vector<ll>&seg,ll qlow, ll qhigh, ll low, ll high, ll pos){
        if (qlow <= low && qhigh>= high){ // total overlap
            return seg[pos];
        }
        if (qlow > high || qhigh < low) { // no overlap
            return LLONG_MAX;
        }
        // partial overlap
        ll mid = low+(high-low)/2;
        return min(rangeUtil(seg,qlow, qhigh, low, mid, 2*pos+1),rangeUtil(seg,qlow, qhigh, mid+1, high, 2*pos+2));
}





void solve(){
   ll n,q;
   cin>>n>>q;
   vector<ll>arr(n);
   for(ll i=0;i<n;i++){
    cin>>arr[i];
   }
   vector<ll>seg(4*n,0);
   buildTree(seg,arr,0,0,n-1);
   for(ll i=0;i<q;i++){
    ll type;
    cin>>type;
    if(type==1){
        ll k,u;
        cin>>k>>u;
        k--;
        updateUtil(seg,0,0,n-1,k,u);


    }else{
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        ll ans=rangeUtil(seg,a,b,0,n-1,0);
        cout<<ans<<endl;

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
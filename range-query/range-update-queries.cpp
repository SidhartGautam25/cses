#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod LLONG_MAX


void propogate(vector<ll>&seg,ll node,ll start,ll end){
    if(start==end){
        return;
    }
    ll left=2*node+1;
    ll right=2*node+2;
    seg[left]=seg[left]+seg[node];
    seg[right]=seg[right]+seg[node];
    seg[node]=0;
}

ll query(vector<ll>&seg,ll node,ll l,ll r,ll ind){
    propogate(seg,node,l,r);
    if(l==r){
        return seg[node];
    }else{
        ll mid=(l+r)/2;
        if(l<=ind && ind<=mid){
            // left
            return query(seg,node*2+1,l,mid,ind);
        }else{
            // right
            return query(seg,node*2+2,mid+1,r,ind);
        }
    }

}

void update(vector<ll>&seg,ll node,ll start,ll end,ll l,ll r,ll val){
    if(end<l || r<start){
        return;
    }
    if(start==end){
        seg[node]+=val;
    }else if(l<=start && end<=r){
        seg[node]+=val;
    }else{
        ll mid=(start+end)/2;
        update(seg,node*2+1,start,mid,l,r,val);
        update(seg,node*2+2,mid+1,end,l,r,val);
    }
}




 
 void buildTree(vector<ll>& seg,vector<ll>&nums, ll pos, ll left, ll right){
        if (left == right){
            seg[pos] = nums[left]; 
            return;
        }
        ll mid = (left+right)/2;
        buildTree(seg,nums, 2*pos+1, left, mid);
        buildTree(seg,nums, 2*pos+2, mid+1, right);
        seg[pos]=0;
    }




 
void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll>arr(n);
    vector<ll>seg(4*n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    buildTree(seg,arr,0,0,n-1);
    // cout<<"seg tree is "<<endl;
    // for(ll i=0;i<seg.size();i++){
    //     cout<<seg[i]<<",";
    // }
    // cout<<endl;
    for(ll i=0;i<q;i++){
        ll type;
        cin>>type;
        if(type==1){
            ll l,r,u;
            cin>>l>>r>>u;
            l--;
            r--;
            update(seg,0,0,n-1,l,r,u);

        }else{
            ll k;
            cin>>k;
            k--;
            ll ans=query(seg,0,0,n-1,k);
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
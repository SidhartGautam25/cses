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
        seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
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



void updateUtil(vector<ll>&seg,ll pos,ll left,ll right,ll index,ll val){
     if(index <left || index >right) return;
        
        // total overlap
        if(left==right){
            if(left==index)
                seg[pos]=val;
            return;
        }

        // partial overlap
        ll mid=(left+right)/2;
        updateUtil(seg,2*pos+1,left,mid,index,val); // left child
        updateUtil(seg,2*pos+2,mid+1,right,index,val); // right child
        seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}




 
void solve(){
  int n,q;
  cin>>n>>q;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<int>prefix(n);
  prefix[0]=arr[0];
  for(int i=1;i<n;i++){
    prefix[i]=prefix[i-1]^arr[i];
  }
  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    l--;
    r--;
    int ans;
    if(l==0){
        ans=prefix[r];
    }else{
        ans=prefix[r]^prefix[l-1];
    }
    cout<<ans<<endl;
    

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
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod LLONG_MAX

 
 
void solve(){
   int n,k;
   cin>>n>>k;
   vector<int>arr(n,0);
   for(int i=0;i<n;i++){
      string s;
      cin>>s;
      for(int j=0;j<k;j++){
        if(s[j]=='1'){
            arr[i]=arr[i]+(1<<j);
        }
      }
   }
   int ans=32;
   for(int i=0;i<n;i++){
     for(int j=i+1;j<n;j++){
        ans=min(ans, (int) __builtin_popcount(arr[i]^arr[j]));
     }
   }
   cout<<ans<<endl;
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
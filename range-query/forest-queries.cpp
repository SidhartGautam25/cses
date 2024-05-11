#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod LLONG_MAX



 
void solve(){
   int n,q;
   cin>>n>>q;
   vector<vector<int>>forest(n,vector<int>(n));
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        char c;
        cin>>c;
        if(c=='.'){
            forest[i][j]=0;
        }else{
            forest[i][j]=1;

        }
    }
   }
   vector<vector<int>>dp(n,vector<int>(n,0));
   

 
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
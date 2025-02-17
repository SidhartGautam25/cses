
  #include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX




int main(){

   int n;
   cin>>n;
   vector<int>arr(n);
   map<int,int>mp;
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   int curr=1;
   int mmax=1;
   int start=0;
  

   for(int i=0;i<n;i++){
      if(mp.find(arr[i])==mp.end()){
        
        mmax=max(mmax,i-start+1);
        mp[arr[i]]=i;

      }else{
        start=max(start,mp[arr[i]]+1);
        mmax=max(mmax,i-start+1);
        mp[arr[i]]=i;

      }
   }

   cout<<mmax<<endl;










}
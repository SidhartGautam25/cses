
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
        mp[arr[i]]=i;
     }
     int steps=1;
     for(int i=2;i<=n;i++){
        if(mp[i]<mp[i-1]){
            steps++;

        }else{
            continue;

        }
     }


     cout<<steps<<endl;










}
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX




void solutionOne(){
   

   ll n;
   cin>>n;
   vector<ll>arr(n);
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }

   ll curr=arr[0];
   ll mmax=arr[0];

   for(int i=1;i<n;i++){
     if(curr<0){
        curr=0;
      }
      curr=curr+arr[i];
      mmax=max(mmax,curr);
     
   }

   cout<<mmax<<endl;




}

int main(){

    solutionOne();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX

// greedy approach
int main(){
   int n,x;
   cin>>n>>x;
   vector<int>arr(n);

   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   sort(arr.begin(),arr.end());

   int l=0;
   int r=n-1;



   int count=0;

   while(l<=r){
        
        if(arr[l]+arr[r]<=x){
            count++;
            r--;
            l++;
        }else{
            count++;
            r--;

        }




   }



   cout<<count<<endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX


bool possible(vector<ll>&arr,int k,ll max_sum){
    int count=0;
    ll currSum=0;

    for(int i=0;i<arr.size();i++){
        int x=arr[i];
        if(x>max_sum){
            return false;
        }

        if(currSum+x>max_sum){
            count++;
            currSum=0;
        }


        currSum+=x;
    }


    if(currSum>0){
        count++;
    }

    if(count<=k){
        return true;
    }

    return false;






}

void solutionOne(){
   

   int n,k;
   cin>>n>>k;

   vector<ll>arr(n);

   for(int i=0;i<n;i++){
    cin>>arr[i];
   }

   ll l = *max_element(begin(arr), end(arr));
   ll r = accumulate(begin(arr), end(arr), 0LL);

   while(l<r){
      ll mid=(l+r)/2;
      if(possible(arr,k,mid)){
        r=mid;
      }else{
        l=mid+1;
      }
   }

   cout<<l<<endl;





}

int main(){

    solutionOne();

    return 0;
}
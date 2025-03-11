#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX




void solutionOne(){


    int n,t;
    cin>>n>>t;

    vector<int>arr(n);

    int mmax=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mmax=max(mmax,arr[i]);
    }

    ll lo=0;
    ll hi=mmax*t;

    ll ans=0;

    while(lo<=hi){
        ll mid=(lo+hi)/2;
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=(mid/arr[i]);
            if(sum>=t){
                break;
            }
        }

        if(sum>=t){
            ans=mid;
        }else{
            lo=mid+1;
        }
    }

    cout<<ans<<endl;




    


   


   

  




}

int main(){

    solutionOne();

    return 0;
}
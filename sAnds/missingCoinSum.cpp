
  #include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX




int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());

    // assuming our ans will be 1
    ll x=1;
    // also, x is the prefix sum of the array till the visited index + 1
    for(int i=0;i<n;i++){
        if(arr[i]>x){
            cout<<x<<endl;
            return 0;
        }
        x=x+arr[i];
    }
    cout<<x<<endl;
    return 0;
   









}
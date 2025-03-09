#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX



bool findSum(int rem,vector<pair<int,int>>&arr,int& start,int& end){

    while(start<end){
        int sum=arr[start].first+arr[end].first;
        if(sum==rem){
            return true;
        }else if(sum>rem){
            end--;

        }else{
            start++;

        }
    }

    return false;
}



void solutionOne(){
   

    int n,x;
    cin>>n>>x;

    vector<pair<int,int>>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second=i;
    }

    sort(arr.begin(),arr.end());

    
    int end;
    int start;
    
    for(int i=0;i<n-2;i++){
        int rem=x-arr[i].first;
        start=i+1;
        end=n-1;
        bool find=findSum(rem,arr,start,end);
        if(find){
            int j=arr[start].second;
            int k=arr[end].second;
            int f=arr[i].second;
            cout<<f+1<<" "<<j+1<<" "<<k+1<<endl;
            return;

        }
    }


    cout<<"IMPOSSIBLE"<<endl;





}

int main(){

    solutionOne();

    return 0;
}
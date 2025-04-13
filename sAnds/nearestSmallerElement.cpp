#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007


void read_iv(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void read_ipv(vector<pair<int,int>>& arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        arr[i].first=x;
        arr[i].second=y;
    }
}

void print_iv(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void read_i(int& x){
    cin>>x;
}




void solutionOne() {


    int n;
    read_i(n);
    vector<int>arr(n);
    read_iv(arr);

    stack<pair<int,int>>stk;

    for(int i=0;i<n;i++){
        int x=arr[i];
        if(stk.size()==0){
            cout<<"0"<<" ";
            stk.push(make_pair(x,i+1));
            continue;
        }
        while(stk.top().first>=x){
            stk.pop();
            if(stk.size()==0){
                break;
            }

        }
        if(stk.size()==0){
            cout<<"0"<<" ";
            stk.push(make_pair(x,i+1));
            continue;
        }

        cout<<stk.top().second<<" ";
        stk.push(make_pair(x,i+1));

    }
    cout<<endl;
  
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solutionOne();

    return 0;
}

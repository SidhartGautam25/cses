
  #include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX




int main(){
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        // mp[arr[i]]=i;
    }
    bool found=false;


    for(int i=0;i<n;i++){
        int curr=arr[i];
        if(mp.find(x-curr) != mp.end()){
            found=true;
            // int mmax=max(mp[curr],mp[x-curr]);
            // int mmin=min(mp[curr],mp[x-curr]);
            // cout<<mmin<<" "<<mmax<<endl;
            cout<<mp[x-curr]+1<<" "<<i+1<<endl;
            break;
        }
        mp[curr]=i;
    }








   
    if(found==false){
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;


}
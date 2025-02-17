#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX

// greedy approach
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>price(n);
    vector<int>money(m);
    map<int,int>mp;

    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<m;i++){
        cin>>money[i];
        mp[i]=money[i];
    }

    sort(price.begin(),price.end());
    sort(money.begin(),money.end());

    int i=0;
    int j=0;
    int count=0;
    while(i<m and j<n){
        if(price[j]<=money[i]){
            count++;
            i++;
            j++;
        }else{
            //agr price jaida hai
            i++;
        }

    }
    cout<<count<<endl;
 

    return 0;
}
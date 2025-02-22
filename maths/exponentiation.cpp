#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX
const int MOD = 1000000007;

int firstHelper(int b,int e){
    if(e==0){
        return 1;
    }

    if(e==1){
        return b%MOD;
    }

    ll midAns=firstHelper(b,e/2);  
    if(e%2==0){
        return (midAns*midAns)%MOD;
    } else{
        return (((midAns * midAns) % MOD) * b) % MOD;
    }

}

void first(){
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        int ans=firstHelper(a,b);
        cout<<ans<<endl;
    }
}




int main(){
    first();
  

    return 0;
}
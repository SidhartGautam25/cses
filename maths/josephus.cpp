#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX
const int MOD = 1000000007;



ll recursion_2(ll n, ll k) {
    if (n == 1) return 1;

    
    if (n % 2 == 0) {
        if (k <= n / 2) return 2 * k;
        return 2 * recursion_2(n / 2, k - n / 2) - 1;
    }

    else {
        ll first_pass_count = n / 2; 

        if (k <= first_pass_count) {
            return 2 * k;
        }

        ll survivor_count = (n + 1) / 2;
        ll res = recursion(survivor_count, k - first_pass_count);

        
        res = res - 1; 
        if (res == 0) res = survivor_count;
        return 2 * res - 1;
    }
}



int recursion(int n,int k){
    if(n==1){
        return n;
    }

    int deletion=(n+1)/2;
    if(k<= deletion){
        if (2 * k > n) return (2 * k) % n;
        return 2 * k;
    }

    int rem_n=n/2;
    int rem_k=k-deletion;
    int res=recursion(rem_n,rem_k);
    if(n%2==0){
        return res*2-1;
    }else{
        return 2*res+1;
    }
}

void first(){
  

    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int n,k;
        cin>>n>>k;
        int result=recursion(n,k);
        cout<<result<<endl;
    }
    
}




int main(){
    first();
  

    return 0;
}
#include<bits/stdc++.h>
using namespace std;



void solutionOne(){
    long long n;
    cin>>n;
    vector<long long>books(n);
    long long total=0;
    long long mmax=0;
    for(int i=0;i<n;i++){
        cin>>books[i];
        total=total+books[i];
        mmax=max(mmax,books[i]);
    }

    if(mmax<=(total/2)){
        cout<<total<<endl;
        return;
    }else{
        cout<<2*mmax<<endl;
        return;
    }

}

int main(){

    solutionOne();

    return 0;
}
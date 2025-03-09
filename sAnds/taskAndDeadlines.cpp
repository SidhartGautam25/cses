#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX



void solutionOne(){
   ll n;
   cin>>n;
 
   vector<pair<ll,ll>>task(n);

   for(int i=0;i<n;i++){
    cin>>task[i].first>>task[i].second;
   }

   sort(task.begin(),task.end());

   ll currTime=0;
   ll reward=0;

   for(int i=0;i<n;i++){

       currTime+=task[i].first;
       reward+=(task[i].second-currTime);

   }

   cout<<reward<<endl;






}

int main(){

    solutionOne();

    return 0;
}
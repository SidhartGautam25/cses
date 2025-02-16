#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX

// greedy approach
int main(){
   int n,m,k;
   cin>>n>>m>>k;

   vector<int>applicants(n);
   vector<int>apratments(m);

   for(int i=0;i<n;i++){
    cin>>applicants[i];
   }
   for(int i=0;i<m;i++){
    cin>>apratments[i];
   }
   sort(applicants.begin(),applicants.end());
   sort(apratments.begin(),apratments.end());
   int i=0;
   int j=0;
   int count=0;
   while(i<n and j<m){
     if(abs(applicants[i]-apratments[j])<=k){
        i++;
        j++;
        count++;
     }else{
        // apartment bda nikal jaye tb
        if(apratments[j]>(applicants[i]+k)){
            i++;
        }
        // demand is more than the required size
        else{
            j++;
        }
     }
   }
   cout<<count<<endl;


    return 0;
}
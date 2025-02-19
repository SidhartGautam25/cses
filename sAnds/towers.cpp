
  #include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX




int main(){

    /*

    see for any specific number,we have to search the tower whose
    topmost cube is just larger than the current cube width for 
    minimum count

    whenever the problem is like this we use binary search
    
    
    */


    // using dynamic array

    int n;
    cin>>n;
    vector<int>arr;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        int lo=0;
        int hi=arr.size();

        while(lo<hi){
            int mid=(lo+hi)/2;
            if(arr[mid]>x){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }

        if(lo==arr.size()){
            // if this case is happening
            // that means ye jo x hai usse bda koi element mila nhi
            // aise me hmko x ko array me insert karna pdega
            arr.push_back(x);
        }else{
            arr[lo]=x;
        }
    }

    cout<<arr.size()<<endl;


   




  









}
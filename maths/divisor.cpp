#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX
const int MOD = 1000000007;


void calculateDivisors(long long numDivisors[])
{
    for (int i = 1; i < 1000005; i++) {
        for (int j = i; j < 1000005; j += i) {
            numDivisors[j]++;
        }
    }
}

void first(){
    int n;
    cin>>n;

     long long numDivisors[1000005] = {};

    // Call the function to calculate the number of divisors
    calculateDivisors(numDivisors);
    
    for(int i=0;i<n;i++){
       int x;
       cin>>x;
        cout << numDivisors[x] << "\n";

    }
}




int main(){
    first();
  

    return 0;
}
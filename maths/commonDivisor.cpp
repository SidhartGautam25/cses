#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX
const int MOD = 1000000007;
const int MAX_VAL = 1e6;
int divisors[MAX_VAL + 1];




void first(){
    int n;
    cin>>n;

    for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		const int up = (int)sqrt(a);
		for (int div = 1; div <= up; div++) {
			if (a % div == 0) {
				// the divisor and quotient are both divisors of a
				divisors[div]++;
				// make sure not to double count!
				if (div != a / div) { divisors[a / div]++; }
			}
		}
	}

	for (int i = MAX_VAL; i >= 1; i--) {
		if (divisors[i] >= 2) {
			cout << i << endl;
			break;
		}
	}

     
   
}




int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    first();
  

    return 0;
}
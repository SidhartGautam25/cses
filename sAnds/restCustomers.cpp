#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX




int main(){

// this approach has better time complexity 
// but since to solve his we are making an extra array that
// has size equal to mmax+2 it is not feasible
/*
    ll n;
    cin>>n;
    vector<pair<ll,ll>>time(n);
    ll mmin=0;
    ll mmax=0;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        time[i]=make_pair(a,b);
        mmin=min(mmin,a);
        mmax=max(mmax,b);
    }
    vector<ll>line(mmax+2,0);
    for(ll i=0;i<n;i++){
        line[time[i].first]+=1;
        line[time[i].second+1]-=1;
    }
    ll ans=0;
    ll sum=0;
    for(ll i=0;i<line.size();i++){
        sum=sum+line[i];
        ans=max(ans,sum);

    }

    
  



    cout<<ans<<endl;
    */


int n;
	cin >> n;
	vector<pair<int, int>> times;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		times.push_back({start, 1});
		times.push_back({end, -1});
	}

	sort(times.begin(), times.end());

	int curr = 0;
	int mmax = 0;
	for (const pair<int, int> &t : times) {
		curr += t.second;
		mmax = max(mmax, curr);
	}

	cout << mmax << endl;
    

  

    return 0;
}
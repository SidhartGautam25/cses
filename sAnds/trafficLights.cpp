
  #include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX




int approachFirst(){
    // time limit exceeded

    // but learnt to use set and multiset in problem like this

    set<pair<int,int>>ranges;
    multiset<ll>range_lengths;
    int x,n;
    cin>>x>>n;

    ranges.insert({0,x});
    range_lengths.insert(x);

    for(int i=0;i<n;i++){
        int pos;
        cin>>pos;

        auto it=ranges.upper_bound({pos,0});
        it--;

        ll start=it->first;
        ll end=it->second;

        ranges.erase(it);

        range_lengths.erase(range_lengths.find(end-start));


        ranges.insert({start,pos});
        ranges.insert({pos,end});
        range_lengths.insert({pos-start});
        range_lengths.insert({end-pos});

        cout << *range_lengths.rbegin() << "\n";

        

    }


    return 0;


}


void approachSecond(){

// these two line is important my friend
    ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x;
	int n;
	cin >> x >> n;

	set<int> lights{0, x};
	multiset<int> rangeLengths{x};
	for (int l = 0; l < n; l++) {
		int pos;
		cin >> pos;

		auto it1 = lights.upper_bound(pos);
		auto it2 = it1;
		--it2;

		rangeLengths.erase(rangeLengths.find(*it1 - *it2));
		rangeLengths.insert(pos - *it2);
		rangeLengths.insert(*it1 - pos);
		lights.insert(pos);

		auto ans = rangeLengths.end();
		--ans;
		cout << *ans << " ";
	}
   
    
}

void approachThird(){

    int x;
	int n;
	std::cin >> x >> n;
	vector<int> lights(n);
	for (int &l : lights) { std::cin >> l; }

	vector<std::pair<int, int>> sorted_lights(n);
	for (int l = 0; l < n; l++) { sorted_lights[l] = {lights[l], l}; }
	std::sort(sorted_lights.begin(), sorted_lights.end());

	// Given the light position, this array stores its position in
	// sorted_lights.
	vector<int> new_pos(n);
	for (int l = 0; l < n; l++) { new_pos[sorted_lights[l].second] = l; }

	struct Light {
		int prev, next;
		int pos;
	};
	vector<Light> light_ll(n + 2);
	// First, we set our "lights" on the edges of the street.
	light_ll[0] = {-1, 1, 0};
	light_ll[n + 1] = {n, -1, x};
	for (int l = 0; l < n; l++) {
		light_ll[l + 1] = {l, l + 2, sorted_lights[l].first};
	}

	// Find the longest passage once all the streetlights are added
	vector<int> gaps(n);
	int max_gap = 0;
	for (int l = 0; l <= n; l++) {
		max_gap = std::max(max_gap, light_ll[l + 1].pos - light_ll[l].pos);
	}
	gaps.back() = max_gap;

	// Remove the streetlights in reverse order like as we did in the above
	// solution.
	for (int l = n - 1; l > 0; l--) {
		Light to_del = light_ll[new_pos[l] + 1];
		Light &left = light_ll[to_del.prev];
		Light &right = light_ll[to_del.next];
		// Re-assign the references to the next & previous node
		left.next = to_del.next;
		right.prev = to_del.prev;

		max_gap = std::max(max_gap, right.pos - left.pos);
		gaps[l - 1] = max_gap;
	}

	for (int i = 0; i < gaps.size() - 1; i++) { cout << gaps[i] << ' '; }
	cout << gaps.back() << endl;



}

void approachFourth(){
    int x;
	int n;
	std::cin >> x >> n;
	vector<int> lights(n);
	for (int &l : lights) { std::cin >> l; }
	// Initialize the set with beginning and ending values
	std::set<int> street_pos{0, x};
	for (int l : lights) { street_pos.insert(l); }

	vector<int> gaps(n);
	int prev = 0;
	int max_gap = 0;
	// Find the longest passage once all the streetlights are added
	for (int p : street_pos) {
		max_gap = std::max(max_gap, p - prev);
		prev = p;
	}
	gaps.back() = max_gap;

	/*
	 * Remove the streetlights in reverse order to how they were added, then
	 * find the gap created by removing each. Find the biggest current gap, and
	 * add it to the next lowest index in answer.
	 */
	for (int i = n - 1; i > 0; i--) {
		street_pos.erase(lights[i]);
		auto high_it = street_pos.upper_bound(lights[i]);
		int high = *high_it;
		int low = *(--high_it);
		max_gap = std::max(max_gap, high - low);
		gaps[i - 1] = max_gap;
	}

	for (int i = 0; i < gaps.size() - 1; i++) { cout << gaps[i] << ' '; }
	cout << gaps.back() << endl;
}



int main(){
    approachSecond();


   
    

    return 0;
}
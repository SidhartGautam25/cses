#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod INT_MAX


// activity selection problem

int main(){

    int n;
    cin>>n;
    vector<pair<int,int>>movies(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        movies[i].first=a;
        movies[i].second=b;
    }

    // our aim should be
    // 1. Finish each movie as early as possible 
    // 2. Avoid overlaps by selecting movies wisely.

    // Approach


    // Sort the movies by their ending times in ascending order

    // Iterate through the movies and always choose the earliest finishing
    // movie that does not overlap with the last chosen one.

     sort(movies.begin(), movies.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

     int count = 0, lastEnd = 0;

     for (const auto& movie : movies) {
        if (movie.first >= lastEnd) { // If movie starts after or when the last selected one ends
            count++;
            lastEnd = movie.second; // Update last ending time
        }
    }

    cout << count << "\n";



  

    return 0;
}
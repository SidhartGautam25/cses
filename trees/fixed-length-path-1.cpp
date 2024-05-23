#include<bits/stdc++.h>
using namespace std;
#define SZ 200005

vector<int> a[SZ];
int s[SZ], countArr[SZ], n, k, m;
long long ans;
bool v[SZ];

void SUBTREE_SIZE_CALC(int u, int p) {
    s[u]=1;
    for(int x: a[u]) {
        if(!v[x] && x!=p) {
            SUBTREE_SIZE_CALC(x, u);
            s[u] += s[x]; 
        }
    }
}

int FIND_CENTROID(int u, int p, int t) {
    for(int x: a[u]) {
        if(!v[x] && x!=p && s[x]>t) {
            return FIND_CENTROID(x, u, t);
        }
    }
    return u;
}

void dfs(int u, int p, int d, bool c) {
    if(d>k) return;
    if(c) {
        ans += countArr[k-d];
    }
    else {
        countArr[d]++;
    }
    m = max(m, d);

    for(int x: a[u]) {
        if(!v[x] && x!=p) {
            dfs(x, u, d+1, c);
        }
    }
}

void cd(int u) {
    // we are calculating the size of subtree
    SUBTREE_SIZE_CALC(u, -1);

    // get the centroid
    int c = FIND_CENTROID(u, -1, s[u]/2);
    // this array is just setting for indices which are previosly calculated
    // as centroid 
    v[c] = true;

    // this array is just storing the count of nodes at depth d for given centroid
    countArr[0] = 1;

    // this is just for erasing the countArr 
    m = 0;
    for(int x: a[c]) {
        if(!v[x]) {
            // first dfs is just calculating the count of node at depth d
            dfs(x, c, 1, true);

            //second dfs calculates the count of path of length k passing through
            // our centroid 
            dfs(x, c, 1, false);
        }
    }

    // just erasing the values from countArr
    fill(countArr, countArr+m+10, 0);
    for(int x: a[c]) {
        //now go to neighbour of current centroid 
        if(!v[x]) {
            cd(x);
        }
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    cd(1);
    cout << ans;
}
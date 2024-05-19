#include "bits/stdc++.h"
using namespace std;

const int SIZE = 2e5 + 5;
const int DEPTH = 19;
const int SEGMENT = (1 << DEPTH);

int nodes, queries, values[SIZE];
vector<int> tree[SIZE];

int subtree_size[SIZE], parent[SIZE], depth[SIZE];
int STree[SEGMENT], hldArray[SIZE], head[SIZE];

void updateSTree(int index, int value) {
	STree[index + nodes] = value;
    index=index+nodes;
    int mid=index/2;

	for (int i=mid; i>0;i=i/2) {
		STree[i] = max(STree[2 * i], STree[2 * i + 1]);
	}
}

int query(int a, int b) {
	a += nodes, b += nodes;
	int result = 0;

	while (a <= b) {
        //right child
		if (a & 1) {
			result = max(result, STree[a]);
			a++;
		}
        //left child
		if (~b & 1) {
			result = max(result, STree[b]);
			b--;
		}
		a /= 2, b /= 2;
	}
	return result;
}

int DFS(int node, int parent_node) {
	subtree_size[node] = 1;
	parent[node] = parent_node;

	for (int child : tree[node]) {
		if (child == parent_node) continue;

		depth[child] = depth[node] + 1;
		parent[child] = node;
		subtree_size[node] += DFS(child, node);
	}
	return subtree_size[node];
}

int counter = 1;		

void DFS_HLD(int node, int parent_node, int top) {
	hldArray[node] = counter++;
	head[node] = top;

	updateSTree(hldArray[node], values[node]);

	int heavy_child = -1, heavy_size = -1;

	for (int child : tree[node]) {
		if (child == parent_node) continue;

		if (subtree_size[child] > heavy_size) {
			heavy_size = subtree_size[child];
			heavy_child = child;
		}
	}
	if (heavy_child == -1) return;

	DFS_HLD(heavy_child, node, top);

	for (int child : tree[node]) {
		if (child == parent_node || child == heavy_child) continue;

		DFS_HLD(child, node, child);
	}
}

int findAns(int x, int y) {
	int answer = 0;
	while (head[x] != head[y]) {
		if (depth[head[x]] < depth[head[y]]) {
			swap(x, y);
		}
		answer = max(answer, query(hldArray[head[x]], hldArray[x]));
		x = parent[head[x]];
	}
	if (depth[x] > depth[y]) {
		swap(x, y);
	}
	answer = max(answer, query(hldArray[x], hldArray[y]));
	return answer;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> nodes >> queries;

	for (int i = 1; i <= nodes; i++) {
		cin >> values[i];
	}
	for (int i = 2; i <= nodes; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	DFS(1, 0);
	DFS_HLD(1, 0, 1);

	while (queries--) {
		int type;
		cin >> type;
		if (type == 1) {
			int s, x;
			cin >> s >> x;
			values[s] = x;
			updateSTree(hldArray[s], values[s]);
		} else {
			int a, b;
			cin >> a >> b;

			int result = findAns(a, b);
			cout << result << " ";
		}
	}
}
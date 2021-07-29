#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> adj[n];
	for (int i = 0; i < m; i++) {
		int u, v, wt;
		adj[u].push_back({v, wt});
		adj[v].push_back(u, wt
	});


	int parent[n];
	int key[n];
	bool mstSet[n];

	for (int i = 0; i < n; i++) {
	key[i] = INT_MAX, mstSet[i] = false;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	key[0] = 0;
	parent[0] = -1;
	pq.push({0, 0});  // value, index

	for (int i = 0; i < n - 1; i++) {
	int u = pq.top().second; //getting index
		pq.pop();
		mstSet[u] = true;

		for (auto it : adj[u]) {
			int node = it.first;
			int weight = it.second;

			if (mstSet[node] == false && weight < key[u]) {
				parent[node] = u;
				pq.push({key[node], node});
				key[node] = weight;
			}
		}
	}

	for (int i = 1; i < n; i++) {
	cout << parent[i] << " - " << i << "\n";
	}

	return 0;
}
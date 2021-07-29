#include<bits/stdc++.h>
using namespace std;

bool solve(int node, int k, vector<bool> &vis, vector<int> g[]) {
	vis[node] = true;
	if (k <= 0) return true;

	for (auto x : g[node]) {
		int u = x.first;
		int w = x.second;
		if (vis[u] == true) continue;

		if (w >= k) return true;

		if (solve(u, k - w, vis, g)) {
			return true;
		}
	}
	vis[node] = false;
	return false;
}

int main() {
	int v, e;
	cin >> v >> e;
	int k;
	cin >> k;
	vector<pair<int, int>> g[v];

	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> w;
		g[x].push_back({v, w});
		g[x].push_back({u, w});
	}

	vector<bool> vis(v, false);

	cout << solve(1, k, vis, g);
	return 0;
}
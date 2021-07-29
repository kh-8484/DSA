#include<bits/stdc++.h>
using namespace std;

vector<int> order;

void topo(int node, vector<int> &vis, vector < vector<pair<int, int>> g) {
	vis[node] = 1;
	for (auto x : g[node]) {
		if (!vis[x.first]) {
			topo(x.first, vis, g);
		}
	}
	order.push_back(node);
}

int main() {
	int v, e;
	cin >> v >> e;

	int src;
	cin >> src;

	vector < vector<pair<int, int>> g(v);
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
	}

	vector<int> vis(v, 0);
	for (int i = 0; i < v; i++) {
		if (!vis[i]) {
			topo(i, vis, g);
		}
	}

	vector<int> dist(v, INT_MIN);
	dist[src] = 0;

	for (int i = v - 1; i >= 0; i--) {
		if (dist[order[i]] != INT_MIN) {
			for (auto x : g[order[i]]) {
				int u = dist[order[i]];
				int v = dist[x.first];
				int w = x.second;
				if (u + w > v) {
					dist[x.first] = u + w;
				}
			}
		}
	}

	for (int i = 0; i < v; i++) {
		if (i != src and dist[i] != INT_MIN) {
			cout << src << " -> " << i << " = " << dist[i] << endl;
		}
	}

	return 0;
}
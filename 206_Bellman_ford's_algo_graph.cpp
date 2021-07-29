#include<bits/stdc++.h>
using namespace std;

struct node {
	int u;
	int v;
	int wt;

	node(int first, int second, int weight) {
		u = first;
		v = second;
		wt = weight;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	vector<node> edges;

	for (int i = 0; i < m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back(node(u, v, wt));
	}

	int src;
	cin >> src;

	vector<int> dist(n, INT_MAX);

	dist[src] = 0;

	for (int i = 0; i < n - 1; i++) {
		for (auto it : edges) {
			if (dist[it.u] + it.wt < dist[it.v]) {
				dist[it.v] = dist[it.u] + it.wt;
			}
		}
	}

	int fl = 0;
	for (auto it : edges) {
		if (dist[it.u] + it.wt < dist[it.v]) {
			cout << "Negative Cycle";
			fl = 1;
			break;
		}
	}

	if (!fl) {
		for (int i = 0; i < N; i++) {
			cout << i << " " << dist[i] << endl;
		}
	}

	return 0;
}
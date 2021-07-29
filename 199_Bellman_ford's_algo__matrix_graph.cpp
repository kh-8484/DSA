int m = edges.size();

vector<int> dist(n, INT_MAX);

dist[0] = 0;

for (int i = 1; i <= n - 1; i++) {

	bool is_updating = true;

	for (int j = 0; j < m; j++) {

		int u = edges[j][0];
		int v = edges[j][1];
		int weight = edges[j][2];

		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {

			dist[v] = dist[u] + weight;
			is_updating = false;
		}
	}

	if (is_updating == true) {
		break;
	}
}

for (int j = 0; j < m; j++) {

	int u = edges[j][0];
	int v = edges[j][1];
	int weight = edges[j][2];

	if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
		return 1;
	}
}
return 0;
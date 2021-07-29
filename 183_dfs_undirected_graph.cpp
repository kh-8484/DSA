void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
	storeDfs.push_back(node);
	vis[node] = 1;
	for (auto it : adj[node]) {
		if (!vis[it]) {
			dfs(it, vis, adj, storeDfs);
		}
	}
}

void main() {

	vector<int> dfsofGraph(int V, vector<int> adj[]) {
		vector<int> dfs;
		vector<int> vis(V, 0);

		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfs(i, vis, adj, dfs)
			}
		}
		return bfs;
	}
}
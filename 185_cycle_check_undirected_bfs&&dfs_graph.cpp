// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution
{
private:
	bool checkCycleBfs(int node, vector<int> &vis, vector<int> adj[]) {
		queue<pair<int, int>> q;
		vis[node] = 1;
		q.push({node, -1});

		while (!q.empty()) {
			int node = q.front().first;
			int prev = q.front().second;
			q.pop();

			for (auto it : adj[node]) {
				if (!vis[it]) {
					vis[it] = 1;
					q.push({it, node});
				}
				else if (prev != it) {
					return true;
				}
			}
		}
		return false;
	}

	bool checkCycleDfs(int node, int prev, vector<int> &vis, vector<int> adj[]) {
		vis[node] = 1;
		for (auto it : adj[node]) {
			if (!vis[it]) {
				if (checkCycleDfs(it, node, vis, adj)) return true;
			}
			else if (it != prev) return true;
		}
		return false;
	}

public:
	//Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
		// Code here
		vector<int> vis(V, 0);

		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				//if(checkCycleBfs(i, vis, adj)) return true;
				if (checkCycleDfs(i, -1, vis, adj)) return true;
			}
		}
		return false;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if (ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
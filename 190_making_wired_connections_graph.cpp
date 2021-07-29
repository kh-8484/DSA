class Solution {
public:
    void dfs(int node, vector<int> g[], vector<int> &vis) {
        vis[node] = 1;
        for (auto x : g[node]) {
            if (!vis[x]) {
                dfs(x, g, vis);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> g[n];
        int m = connections.size();
        if (n - 1 > m) return -1;

        for (int i = 0; i < m; i++) {
            g[connections[i][0]].push_back(connections[i][1]);
            g[connections[i][1]].push_back(connections[i][0]);
        }

        vector<int> vis(n, 0);
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                c++;
                dfs(i, g, vis);
            }
        }
        return c - 1;
    }
};
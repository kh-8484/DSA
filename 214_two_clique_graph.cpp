#include <bits/stdc++.h>
using namespace std;

bool bipartiteBfs(int src, vector<int> adj[], int color[]) {
    queue<int> q;
    q.push(src);
    color[src] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : adj[node]) {
            if (color[it] == -1) {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node]) {
                return false;
            }
        }
    }
    return true;
}
bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color);
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!bipartiteBfs(i, adj, color)) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> revG[n];
    vector<int> dummy(n, 0);

    for (int i = 0; i < v; i++) {
        dummy[i] = 1;
        for (auto x : adj[i]) {
            dummy[x] = 1;
        }

        for (int j = 0; j < v; j++) {
            if (dummy[j] == 0) {
                revG[i].push_back(j);
                revG[j].push_back(i);
            }
        }
        dummy.clear();
    }

    if (checkBipartite(revG, n)) {
        cout << "Two Clique";
    } else {
        cout << "Not Possible";
    }
    return 0;
}

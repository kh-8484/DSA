#include<bits/stdc++.h>
using namespace std;


void dfs(int node, vector<int> &vis, vector<int> g[], int &counter) {
    vis[node] = 1;
    counter++;
    for (auto x : g[node]) {
        if (!vis[x]) {
            dfs(x, vis, g, counter);
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<int> g[v];
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> vis(v, 0);
    vector<int> solution;
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            int counter = 0;
            dfs(i, vis, g, counter);
            solution.push_back(counter);
        }
    }

    long long int val = v;
    val *= (v - 1);
    val /= 2;
    for (long int i = 0; i < solution.size(); i++) {
        long long int x = solution[i];
        x *= (solution[i] - 1);
        x /= 2;
        val -= x;
    }

    cout << val;
    return 0;
}


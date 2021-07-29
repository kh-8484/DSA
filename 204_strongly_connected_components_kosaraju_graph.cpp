// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution
{
public:
    //Function to find number of strongly connected components in the graph.
    vector<int> order;

    void dfs(int node, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1;
        for (auto x : adj[node]) {
            if (!vis[x]) {
                dfs(x, vis, adj);
            }
        }
        order.push_back(node);
    }
    void rdfs(int node, vector<int> &vis1, vector<int> rev[]) {
        vis1[node] = 1;
        for (auto x : rev[node]) {
            if (!vis1[x]) {
                rdfs(x, vis1, rev);
            }
        }
    }

    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        order.clear();
        vector<int> rev[V];
        for (int i = 0; i < V; i++) {
            for (auto x : adj[i]) {
                rev[x].push_back(i);
            }
        }

        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj);
            }
        }

        vector<int> vis1(V, 0);
        int c = 0;
        for (int i = V - 1; i >= 0; i--) {
            if (!vis1[order[i]]) {
                rdfs(order[i], vis1, rev);
                c++;
            }
        }

        return c;
    }
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
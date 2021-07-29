// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    void dfs(int i, int j, vector<vector<char>> &grid, int n, int m, vector<vector<int>> &vis) {
        if (i<0 or j<0 or i >= n or j >= m) return;
        if (grid[i][j] == '0') return;

        if (!vis[i][j]) {
            vis[i][j] = 1;
            dfs(i + 1, j, grid, n, m, vis);
            dfs(i - 1, j, grid, n, m, vis);
            dfs(i, j + 1, grid, n, m, vis);
            dfs(i, j - 1, grid, n, m, vis);
            dfs(i + 1, j + 1, grid, n, m, vis);
            dfs(i - 1, j - 1, grid, n, m, vis);
            dfs(i + 1, j - 1, grid, n, m, vis);
            dfs(i - 1, j + 1, grid, n, m, vis);
        }
    }
public:
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid, n, m, vis);
                    count++;
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>>grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int maxGold(int n, int m, vector<vector<int>> gold)
    {
        // code here
        for (int col = m - 2; col >= 0; col--) {
            for (int row = 0; row < n; row++) {
                int right = gold[row][col + 1];
                int right_up = row == 0 ? 0 : gold[row - 1][col + 1];
                int right_down = row == n - 1 ? 0 : gold[row + 1][col + 1];
                gold[row][col] = gold[row][col] + max({right, right_up, right_down});
            }
        }
        int res = gold[0][0];
        for (int i = 1; i < n; i++) {
            res = max(res, gold[i][0]);
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> M[i][j];
        }

        Solution ob;
        cout << ob.maxGold(n, m, M) << "\n";
    }
    return 0;
}  // } Driver Code Ends
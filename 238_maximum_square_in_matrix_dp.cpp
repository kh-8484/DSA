// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        //vector<vector<int>> sub_mat;
        int sub_mat[n][m];
        for (int i = 0; i < n; i++) {
            sub_mat[i][0] = mat[i][0];
        }

        for (int j = 0; j < m; j++) {
            sub_mat[0][j] = mat[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][j] == 1) {
                    sub_mat[i][j] = min(sub_mat[i - 1][j], min(sub_mat[i - 1] [j - 1], sub_mat[i][j - 1])) + 1;
                }
                else {
                    sub_mat[i][j] = 0;
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, sub_mat[i][j]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}  // } Driver Code Ends
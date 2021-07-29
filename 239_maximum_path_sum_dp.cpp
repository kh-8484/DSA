// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    int maximumPath(int n, vector<vector<int>> mat)
    {
        // code here
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                //all path possible down , down-left, down-right
                if (j > 0 && j < n - 1) {
                    mat[i][j] += max({mat[i - 1][j], mat[i - 1][j - 1], mat[i - 1][j + 1]});
                }
                //down-right not possible
                else if (j == n - 1) {
                    mat[i][j] += max(mat[i - 1][j], mat[i - 1][j - 1]);
                }
                //down-left not possible
                else if (j == 0) {
                    mat[i][j] += max(mat[i - 1][j], mat[i - 1][j + 1]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, mat[n - 1][i]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for (int i = 0; i < N * N; i++)
            cin >> Matrix[(i / N)][i % N];

        Solution ob;
        cout << ob.maximumPath(N, Matrix) << "\n";
    }
    return 0;
}  // } Driver Code Ends
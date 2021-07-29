// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int dp[1001][1001];
    int solve(int i, int j, int val[], int wt[]) {
        if (i <= -1) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (wt[i] > j) return dp[i][j] = solve(i - 1, j, val, wt);

        int a = solve(i - 1, j, val, wt);
        int b = val[i] + solve(i, j - wt[i], val, wt);
        return dp[i][j] = max(a, b);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        dp[N][W];
        memset(dp, -1, sizeof dp);
        return solve(N - 1, W, val, wt);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
}  // } Driver Code Ends
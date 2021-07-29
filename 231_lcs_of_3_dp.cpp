// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int dp[101][101][101];

int LCS(string &a, string &b, string &c, int n1, int n2, int n3) {
    if (n1 == -1 || n2 == -1 || n3 == -1) return 0;
    if (dp[n1][n2][n3] != -1) return dp[n1][n2][n3];
    if (a[n1] == b[n2] && b[n2] == c[n3]) {
        return dp[n1][n2][n3] = 1 + LCS(a, b, c, n1 - 1, n2 - 1, n3 - 1);
    }
    else {
        int x = LCS(a, b, c, n1 - 1, n2, n3);
        int y = LCS(a, b, c, n1, n2 - 1, n3);
        int z = LCS(a, b, c, n1, n2, n3 - 1);
        return dp[n1][n2][n3] = max({x, y, z});
    }
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    memset(dp, -1, sizeof(dp));
    return LCS(A, B, C, n1 - 1, n2 - 1, n3 - 1);
}
// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    /*You are required to complete below method */
    int dp[1001][1001];
    int mod = 1000000007;
    long long int lps(string &s, int i, int j) {
        if (i == j) {
            return 1;
        }
        if (i > j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] == s[j]) {
            return dp[i][j] = (lps(s, i, j - 1) % mod + lps(s, i + 1, j) % mod + 1) % mod;
        }
        else return dp[i][j] = (lps(s, i, j - 1) % mod + lps(s, i + 1, j) % mod - lps(s, i + 1, j - 1) % mod + mod) % mod;
        //as there is a case where we are substracting so the value can be negative
        //and to take a positive mod we just add mod
    }
    long long int  countPS(string str)
    {
        //Your code here
        int n = str.length();
        dp[n][n];
        memset(dp, -1, sizeof dp);
        long long int ans = lps(str, 0, n - 1);
        return ans % mod;
    }

};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout << ans << endl;
    }
}  // } Driver Code Ends
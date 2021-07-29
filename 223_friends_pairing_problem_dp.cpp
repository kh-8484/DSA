// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int MOD = 1000000007;
    long long int solve(int n, long long int dp[]) {
        if (n <= 2) return n;
        if (dp[n] != -1) {
            return dp[n];
        }
        long long int a = (((n - 1) % MOD) * solve(n - 2, dp) % MOD) % MOD;
        long long int b = solve(n - 1, dp) % MOD;
        return dp[n] = a + b;
    }
    int countFriendsPairings(int n)
    {
        // code here
        // long long int dp[n+1];
        // memset(dp, -1, sizeof dp);
        // return solve(n, dp)%MOD;
        // int dp[n+1];
        // dp[0] =0;
        // dp[1] = 1;
        // dp[2] = 2;
        // for(long long int i=3; i<=n; i++){
        //     dp[i] = (dp[i-1]%MOD + ((i-1)%MOD)*(dp[i-2])%MOD)%MOD;
        // }
        // return dp[n];
        int a = 1, b = 2, c = 0;
        if (n <= 2) {
            return n;
        }
        for (long long int i = 3; i <= n; i++) {
            c = (b % MOD + ((i - 1) * a) % MOD) % MOD;
            a = b;
            b = c;
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
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countFriendsPairings(n);
        cout << endl;
    }
}
// } Driver Code Ends
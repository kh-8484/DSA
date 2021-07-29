// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int dp[1001][1001];

    int solve(int arr[], int n, int s) {
        if (n == -1) {
            if (s == 0) {
                return 1;
            }
            return 0;
        }
        if (s < 0) {
            return 0;
        }
        if (s == 0) {
            return 1;
        }
        if (dp[n][s] != -1) {
            return dp[n][s];
        }

        return dp[n][s] = solve(arr, n - 1, s - arr[n]) || solve(arr, n - 1, s);
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += arr[i];
        }
        if (s & 1) return 0;
        s /= 2;
        dp[n][s];
        memset(dp, -1, sizeof dp);
        return solve(arr, n - 1, s);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}  // } Driver Code Ends
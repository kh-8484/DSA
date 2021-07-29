// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int nCr(int n, int r) {
        // code here
        if (n < r) return 0;
        if ((n - r) < r) r = n - r;
        int mod = 1000000007;
        int dp[r + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = r; j > 0; j--) {
                dp[j] = (dp[j] + dp[j - 1]) % mod;
            }
        }
        return dp[r];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
}  // } Driver Code Ends

TC ---> O(r)
// Program to calculate C(n, k)
#include <bits/stdc++.h>
using namespace std;

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
    int res = 1;

    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;

    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

// Driver Code
int main()
{
    int n = 8, k = 2;
    cout << "Value of C(" << n << ", "
         << k << ") is " << binomialCoeff(n, k);
    return 0;
}

// This is code is contributed by rathbhupendra

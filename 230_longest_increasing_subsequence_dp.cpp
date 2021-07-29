// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution
{
public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // your code here O(n^2)
        //   int dp[n];
        //   for(int i=0; i<n; i++) dp[i] =1;
        //   for(int i=1; i<n; i++){
        //       for(int j=0; j<i; j++){
        //           if(a[j]<a[i]){
        //               dp[i] = max(dp[i], dp[j]+1);
        //           }
        //       }
        //   }
        //   int ma = INT_MIN;
        //   for(int i=0; i<n; i++){
        //       ma = max(ma, dp[i]);
        //   }
        //   return ma;
        int dp[n + 1];
        //memset(dp, INT_MAX, sizeof dp);
        for (int i = 1; i <= n; i++) dp[i] = INT_MAX;
        dp[0] = INT_MIN;
        for (int i = 0; i < n; i++) {
            int idx = upper_bound(dp, dp + n + 1, a[i]) - dp;
            if (dp[idx - 1] < a[i] && dp[idx] > a[i]) {
                dp[idx] = a[i];
            }
        }
        int ans = 0;
        for (int i = n; i >= 0; i--) {
            if (dp[i] != INT_MAX) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        //taking size of array
        cin >> n;
        int a[n];

        //inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends
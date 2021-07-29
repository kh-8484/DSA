// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
public:
    int dp[1000][1000];
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int w, int wt[], int val[], int n) {
        if (w == 0 || n == -1) {
            return 0;
        }
        if (dp[n][w] != -1) {
            return dp[n][w];
        }
        if (wt[n] > w) {
            return dp[n][w] = solve(w, wt, val, n - 1);
        }
        int a, b;
        a  = val[n] + solve(w - wt[n], wt, val, n - 1);
        b  = solve(w, wt, val, n - 1);
        return dp[n][w] = max(a, b);
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        dp[n - 1][W];
        memset(dp, -1, sizeof dp);
        return solve(W, wt, val, n - 1);
    }
};

class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        int i, w;
        int K[n + 1][W + 1];

        //building table K[][] in bottom up manner.
        for (i = 0; i <= n; i++)
        {
            for (w = 0; w <= W; w++)
            {
                //base case
                if (i == 0 || w == 0)
                    K[i][w] = 0;

                //if weight of current item is more than Knapsack capacity W
                //then this item cannot be included in the optimal solution.
                else if (wt[i - 1] <= w)
                    K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);

                //else updating K[i][w] as K[i-1][w].
                else
                    K[i][w] = K[i - 1][w];
            }
        }
        //returning the result.
        return K[n][W];
    }
};
// { Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        //inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        //inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        //calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;

    }
    return 0;
}  // } Driver Code Ends
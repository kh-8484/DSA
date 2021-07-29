// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution {


public:
	int dp[1001][1001];
	int solve(int cost[], int n, int w) {
		if (n == -1 && w == 0) return 0;
		if (n == -1) return 1e9;
		if (w == 0) return 0;
		if (dp[n][w] != -1) return dp[n][w];
		if ((n + 1) > w || cost[n] == -1) return dp[n][w] = solve(cost, n - 1, w);
		int x = solve(cost, n - 1, w);
		int y = cost[n] + solve(cost, n, w - (n + 1));
		return dp[n][w] = min(x, y);
	}
	int minimumCost(int cost[], int n, int w)
	{
		// Your code goes here
		memset(dp, -1, sizeof dp);
		int ans = solve(cost, n - 1, w);
		if (ans >= 1e9) return -1;
		return ans;
	}
};


// { Driver Code Starts.
int main()
{


	int t;
	cin >> t;
	while (t--)
	{
		int n, w;
		cin >> n >> w;

		int a[n];

		for (int i = 0; i < n; i++)
			cin >> a[i];



		Solution ob;
		cout << ob.minimumCost(a, n, w) << "\n";

	}
	return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


//Function to find the maximum possible amount of money we can win.
int dp[1001][1001];
int solve(int i, int j, int arr[]) {
	if (i > j) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	int x = arr[i] + min(solve(i + 2, j, arr), solve(i + 1, j - 1, arr));
	int y = arr[j] + min(solve(i + 1, j - 1, arr), solve(i, j - 2, arr));

	return dp[i][j] = max(x, y);
}
long long maximumAmount(int arr[], int n)
{
	// Your code here
	dp[n][n];
	memset(dp, -1, sizeof dp);
	return solve(0, n - 1, arr);
}

// { Driver Code Starts.

int main() {

	//taking total testcases
	int T;
	cin >> T;
	while (T--)
	{
		//taking number of elements
		int N;
		cin >> N;

		int A[N];

		//inserting the elements
		for (int i = 0; i < N; i++)
			cin >> A[i];

		//calling function maximumAmount()
		cout << maximumAmount(A, N) << endl;

	}
	return 0;
}  // } Driver Code Ends
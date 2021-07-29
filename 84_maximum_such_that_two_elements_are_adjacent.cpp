// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


// } Driver Code Ends


// Function to return maximum of sum without adjacent elements

ll FindMaxSum(ll arr[], ll n)
{
	// Your code here
	ll dp[n];

	if (n < 2) {
		return arr[0];
	}
	dp[0] = arr[0];
	dp[1] = max(arr[0], arr[1]);
	for (int i = 2; i < n; i++) {
		dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
	}
	return dp[n - 1];
}


// { Driver Code Starts.

int main()
{
	//taking total testcases
	int t;
	cin >> t;
	while (t--)
	{
		//taking number of houses
		ll n;
		cin >> n;
		ll a[n];

		//inserting money of each house in the array
		for (ll i = 0; i < n; ++i)
			cin >> a[i];

		//calling function FindMaxSum()
		cout << FindMaxSum(a, n) << endl;
	}
	return 0;
}
// } Driver Code Ends
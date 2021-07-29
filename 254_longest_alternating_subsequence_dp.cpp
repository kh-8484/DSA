// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int AlternatingaMaxLength(vector<int>&nums) {
		// Code here
		int up = 1, down = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > nums[i - 1]) {
				up = down + 1;
			}
			else if (nums[i] < nums[i - 1]) {
				down = up + 1;
			}
		}
		return max(up, down);
	}

};


// Function to return max of two numbers
int max(int a, int b)
{
	return (a > b) ? a : b;
}

// Function to return longest alternating
// subsequence length
int zzis(int arr[], int n)
{

	/*las[i][0] = Length of the longest
	    alternating subsequence ending at         0 for smaller
	    index i and last element is greater
	    than its previous element
	las[i][1] = Length of the longest
	    alternating subsequence ending
	    at index i and last element is         1 for greater
	    smaller than its previous element */
	int las[n][2];

	// Initialize all values from 1
	for (int i = 0; i < n; i++)
		las[i][0] = las[i][1] = 1;

	// Initialize result
	int res = 1;

	// Compute values in bottom up manner
	for (int i = 1; i < n; i++)
	{

		// Consider all elements as
		// previous of arr[i]
		for (int j = 0; j < i; j++)
		{

			// If arr[i] is greater, then
			// check with las[j][1]
			if (arr[j] < arr[i] &&
			        las[i][0] < las[j][1] + 1)
				las[i][0] = las[j][1] + 1;

			// If arr[i] is smaller, then
			// check with las[j][0]
			if (arr[j] > arr[i] &&
			        las[i][1] < las[j][0] + 1)
				las[i][1] = las[j][0] + 1;
		}

		// Pick maximum of both values at index i
		if (res < max(las[i][0], las[i][1]))
			res = max(las[i][0], las[i][1]);
	}
	return res;
}


// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int>nums(n);
		for (int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
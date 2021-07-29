// C++ implementation to find the smallest sum
// contiguous subarray
#include <bits/stdc++.h>

using namespace std;

// function to find the smallest sum contiguous subarray
int smallestSumSubarr(int arr[], int n)
{
	// to store the minimum value that is ending
	// up to the current index
	int sum = INT_MAX;

	// to store the minimum value encountered so far
	int mini = INT_MAX;

	// traverse the array elements
	for (int i = 0; i < n; i++)
	{
		// if sum > 0, then it could not possibly
		// contribute to the minimum sum further
		if (sum > 0)
			sum = arr[i];

		// else add the value arr[i] to sum
		else
			sum += arr[i];

		// update mini
		mini = min(mini, sum);
	}

	// required smallest sum contiguous subarray value
	return mini;
}


// Driver program to test above
int main()
{
	int arr[] = {3, -4, 2, -3, -1, 7, -5};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Smallest sum: "
	     << smallestSumSubarr(arr, n);
	return 0;
}

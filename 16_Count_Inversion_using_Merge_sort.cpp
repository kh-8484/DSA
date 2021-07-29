#include <bits/stdc++.h>
using namespace std;

long long int merge(long long arr[], long long temp[], int left, int mid, int right) {
	long long int i, j, k;
	long long int inv_count = 0;

	i = left; //i is index for left subarray
	j = mid;  //j is index for right subarray
	k = left; //k is index for resultant merged subarray;

	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];

			/* this is tricky -- see above
			explanation/diagram for merge()*/
			inv_count = inv_count + (mid - i);
		}
	}

	/* Copy the remaining elements of left subarray
	(if there are any) to temp*/
	while (i <= mid - 1)
		temp[k++] = arr[i++];

	/* Copy the remaining elements of right subarray
	(if there are any) to temp*/
	while (j <= right)
		temp[k++] = arr[j++];

	/*Copy back the merged elements to original array*/
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

long long int mergeSort(long long arr[], long long temp[], int left, int right) {
	long long int mid, inv_count = 0;

	if (right > left) {
		mid = (left + right) / 2;

		inv_count += mergeSort(arr, temp, left, mid);
		inv_count += mergeSort(arr, temp, mid + 1, right);

		inv_count += merge(arr, temp, left, mid + 1, right);
	}

	return inv_count;
}
long long int inversionCount(long long arr[], long long n)
{
	// Your Code Here
	long long temp[n];
	long long int ans = mergeSort(arr, temp, 0, n - 1);
	return ans;
}


// { Driver Code Starts.

int main() {

	long long T;
	cin >> T;

	while (T--) {
		long long N;
		cin >> N;

		long long A[N];
		for (long long i = 0; i < N; i++) {
			cin >> A[i];
		}

		cout << inversionCount(A, N) << endl;
	}

	return 0;
}
// } Driver Code Ends
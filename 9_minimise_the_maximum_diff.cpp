#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int getMINDIFF(int arr[], int n, int k) {

		if (n == 1)
			return 0;
		sort(arr, arr + n);
		int ans = arr[n - 1] - arr[0];
		int small = arr[0] + k;
		int big = arr[n - 1] - k;
		if (small > big)
			swap(small, big);
		for (int i = 1; i < n - 1; i++)
		{
			int subtract = arr[i] - k;
			int add = arr[i] + k;
			if (subtract >= small || add <= big)
				continue;
			if (big - subtract <= add - small)
				small = subtract;
			else
				big = add;
		}
		return min(ans, big - small);
	}
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> k;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		Solution ob;
		auto ans = ob.getMINDIFF(arr, n, k);
		cout << ans << "\n";
	}
}
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// -10^9 < int < 10^9
// -10^12 < long int < 10^12
// -10^18 < long long int < 10^18

bool solve(int arr[], int n, int m, int mid) {
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] > mid) sum += arr[i] - mid;
	}
	if (sum >= m) return true;
	else return false;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	int T;
	cin >> T;

	while (T--) {

		int n, m;
		cin >> n >> m;

		int arr[n];

		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		int lb = 1;
		int ub = *max_element(arr, arr + n);
		int ans = 0;

		while (lb <= ub) {
			int mid = (lb + ub) / 2;

			if (solve(arr, n, m, mid)) {
				ans = mid;
				lb = mid + 1;
			}
			else
			{
				ub = mid - 1;
			}
		}
		cout << ans << endl;
		// for (int i = 0; i < n; i++) {
		// 	cout << arr[i] << " ";
		// }

	}
	return 0;
}


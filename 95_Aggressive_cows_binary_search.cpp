#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// -10^9 < int < 10^9
// -10^12 < long int < 10^12
// -10^18 < long long int < 10^18

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	int T;
	cin >> T;

	while (T--) {

		int n, c;
		cin >> n >> c;

		int arr[n];

		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		sort(arr, arr + n);

		int lb = 1;
		int ub = 1e9;
		int ans = 0;

		while (lb <= ub) {
			int mid = (lb + ub) / 2;
			int cow = 1;
			int prev = arr[0];
			for (int i = 1; i < n; i++) {
				if (arr[i] - prev >= mid) {
					cow++;
					prev = arr[i];
					if (cow == c)
						break;
				}
			}
			if (cow == c) {
				ans = mid;
				lb = mid + 1;
			}
			else {
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


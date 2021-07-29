#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	int T;

	cin >> T;

	while (T--) {
		int n;

		cin >> n;

		int arr[n];


		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int lo = 0, hi = n - 1, mi = 0, ma = 0, ans = 0;
		while (lo <= hi) {
			if (arr[lo] < arr[hi]) {
				if (arr[lo] > mi) {
					mi = arr[lo];
				}
				else {
					ans = ans + (mi - arr[lo]);
				}
				lo++;
			}
			else {
				if (arr[hi] > ma) {
					ma = arr[hi];
				}
				else {
					ans = ans + (ma - arr[hi]);
				}
				hi--;
			}
		}

		cout << ans << endl;

		// for (int i = 0; i < n; i++) {
		// 	cout << arr[i] << " ";
		// }

	}

}


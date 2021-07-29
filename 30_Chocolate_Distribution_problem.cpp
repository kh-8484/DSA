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

		int m;
		cin >> m;

		sort(arr, arr + n);
		int min = INT_MAX;

		for (int i = 0; i + m - 1 < n; i++) {
			int d = arr[i + m - 1] - arr[i];
			if (d < min) {
				min = d;
			}
		}

		cout << min << endl;

		// for (int i = 0; i < n; i++) {
		// 	cout << arr[i] << " ";
		// }

	}

}

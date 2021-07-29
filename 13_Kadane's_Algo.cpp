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

		int sum = 0;
		int maxi = arr[0];

		for (int i = 0; i < n; i++) {
			sum += arr[i];
			maxi = max(sum, maxi);
			if (sum < 0) {
				sum = 0;
			}
		}

		// for (int i = 0; i < n; i++) {
		// 	cout << arr[i] << " ";
		// }

		cout << maxi << endl;


	}

}


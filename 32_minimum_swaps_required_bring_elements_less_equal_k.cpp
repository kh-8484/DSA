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

		int k;
		cin >> k;

		int good = 0;

		for (int i = 0; i < n; i++) {
			if (arr[i] <= k) {
				good++;
			}
		}

		int bad = 0;
		int mi = INT_MAX;

		for (int i = 0; i < good; i++) {
			if (arr[i] > k) {
				bad++;
			}
		}
		int i = 0, j = good - 1;
		while (j < n) {
			mi = min(mi, bad);
			j++;
			if (j < n && arr[j] > k) {
				bad++;
			}
			if (arr[i] > k) {
				bad--;
			}
			i++;
		}

		if (mi == INT_MAX) {
			cout << 0 << endl;
		}
		else {
			cout << mi << endl;
		}
		// for (int i = 0; i < n; i++) {
		// 	cout << arr[i] << " ";
		// }

	}

}

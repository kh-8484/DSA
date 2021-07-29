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

		int i = 0, j = n - 1;

		while (i <= j) {
			if (arr[i] < 0 && arr[j] > 0) {
				swap(arr[i], arr[j]);
				i++;
				j--;
			}
			else if (arr[i] > 0 && arr[j] < 0) {
				i++;
				j--;
			}
			else if (arr[i] > 0) {
				i++;
			}
			else if (arr[j] < 0) {
				j--;
			}
		}

		if (i == 0 || i == n) {
			for (int m = 0; m < n; i++) {
				cout << arr[m] << " ";
			}
			cout << endl;
		}
		else {
			int k = 0;
			while (k < n && i < n) {
				swap(arr[k], arr[i]);
				i++;
				k += 2;
			}

			for (int m = 0; m < n; m++) {
				cout << arr[m] << " ";
			}
			cout << endl;
		}

	}

}


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
		int n, m;

		cin >> n >> m;

		int arr1[n], arr2[m];


		for (int i = 0; i < n; i++) {
			cin >> arr1[i];
		}


		for (int i = 0; i < m; i++) {
			cin >> arr2[i];
		}

		unordered_map<int, int> m1;

		for (int i = 0; i < n; i++) {
			m1[arr1[i]]++;
		}

		int c = 0;

		for (int i = 0; i < m; i++) {
			if (m1[arr2[i]]) {
				c++;
			}
		}

		if (c != m) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
		}

		// for (int i = 0; i < n; i++) {
		// 	cout << arr[i] << " ";
		// }

	}

}


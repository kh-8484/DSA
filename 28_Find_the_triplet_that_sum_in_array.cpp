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
		int n, x;

		cin >> n >> x;

		int arr[n];


		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		sort(arr, arr + n);

		int ans = 0;

		for (int i = 0; i < n - 2; i++) {
			int l = i + 1;
			int r = n - 1;
			while (l < r) {
				if (arr[i] + arr[l] + arr[r] == x) {
					ans = 1;
					break;
				}
				else if (arr[i] + arr[l] + arr[r] > x) {
					r--;
				}
				else {
					l++;
				}
			}
			if (ans == 1) {
				break;
			}
		}

		cout << ans << endl;



		// for (int i = 0; i < n; i++) {
		// 	cout << arr[i] << " ";
		// }

	}

}


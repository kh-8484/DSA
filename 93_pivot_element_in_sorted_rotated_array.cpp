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

		int n;
		cin >> n;
		int arr[n];

		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		if (arr == NULL || n == 0) {
			return -1;
		}
		// pivot is lowest element in array
		//when array is not rotated so first element is pivot
		if (arr[0] <= arr[n - 1]) {
			return 0;
		}
		int start = 0, end = n - 1;
		while (start <= end) {

			int mid = (start + end) / 2;

			if (arr[mid] > arr[mid + 1]) {
				cout << mid + 1 << endl;
				break;
			}
			else if (arr[start] <= arr[mid]) {
				//it means from start to mid, all elements are
				//in sorted order
				//so pivot will be in second half
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}

		// for (int i = 0; i < n; i++) {
		// 	cout << arr[i] << " ";
		// }

	}
	return 0;
}


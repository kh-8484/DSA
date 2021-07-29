#include <bits/stdc++.h>
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

		// for (int i = n; i >= 0; i--) {
		// 	swap(arr[i], arr[i - 1]);
		// }
		cout << arr[n - 1] << " ";
		for (int i = 0; i < n - 1; i++) {
			cout << arr[i] << " ";
		}

		cout << endl;

	}

}


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
		int n, temp;

		cin >> n;

		int arr[n];

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		sort(arr, arr + n);

		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}

		cout << endl;

	}

}


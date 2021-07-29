#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// -10^9 < int < 10^9
// -10^12 < long int < 10^12
// -10^18 < long long int < 10^18
void I_O() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

bool solve(int arr[], int n, int p, int mid) {
	int time = 0, prata = 0;
	for (int i = 0; i < n; i++) {
		time = arr[i];
		int j = 2;
		while (time <= mid) {
			prata++;
			time += (arr[i] * j);
			j++;
		}
		if (prata >= p) return true;
	}
	return false;
}


int main() {

	I_O();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int T;
	cin >> T;

	while (T--) {
		int p; cin >> p;
		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int lb = 0, ub = 1e8, ans = 0;
		while (lb <= ub) {
			int mid = (lb + ub) / 2;
			if (solve(arr, n, p, mid)) {
				ans = mid;
				ub = mid - 1;
			}
			else {
				lb = mid + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}


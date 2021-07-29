#include <bits/stdc++.h>
using namespace std;

void Dutch_National_Flag_Algo(int arr[], int n) {
	int low = 0;  // 0
	int mid = 0;  // 1
	int high = n - 1; //2

	while (mid <= high) {
		switch (arr[mid]) {
		case 0:
			swap(arr[low++], arr[mid++]);
			break;
		case 1:
			mid++;
			break;
		case 2:
			swap(arr[mid], arr[high--]);
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

}

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

		Dutch_National_Flag_Algo(arr, n);

	}

}


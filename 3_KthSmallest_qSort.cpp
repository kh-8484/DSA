#include <bits/stdc++.h>
using namespace std;


// void kthSmallest(int arr[], int size, int k) {
//   sort(arr, arr+n);
// }
int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
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
		int n, k;

		cin >> n;

		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cin >> k;
// 		sort(arr, arr + n);
		qsort(arr, n, sizeof(int), compare);
		cout << arr[k - 1] << endl;
		// kthSmallest(arr, n, k);
	}

}


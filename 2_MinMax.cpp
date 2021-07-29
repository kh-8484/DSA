#include <bits/stdc++.h>
using namespace std;

struct Pair {
	int min;
	int max;
};

struct Pair getMinMax(int arr[], int size) {
	struct Pair minmax;

	if (size == 1) {
		minmax.min = arr[0];
		minmax.max = arr[0];
		return minmax;
	}

	if (arr[0] > arr[1]) {
		minmax.max = arr[0];
		minmax.min = arr[1];
	}
	else
	{
		minmax.max = arr[1];
		minmax.min = arr[0];
	}

	for (int i = 2; i < size; i++)
	{
		if (arr[i] > minmax.max) {
			minmax.max = arr[i];
		}
		else if (arr[i] < minmax.min) {
			minmax.min = arr[i];
		}
	}

	return minmax;

};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	int n, arr[99];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	struct Pair minmax = getMinMax(arr, n);

	cout << "The minimum element is " << minmax.min << endl <<
	     "The maximum element is " << minmax.max;


}


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


	int n, m;

	cin >> n >> m;

	int arr1[n], arr2[m];

	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}


	int p = n - 1;
	int q = 0;

	while (p >= 0 && q < m) {

		if (arr1[p] > arr2[q])
		{
			swap(arr1[p], arr2[q]);
		}
		else
		{
			break;
		}

		p--;
		q++;

	}
	sort(arr1, arr1 + n);
	sort(arr2, arr2 + m);


	for (int i = 0; i < n; i++) {
		cout << arr1[i] << " ";
	}


	for (int i = 0; i < m; i++) {
		cout << arr2[i] << " ";
	}

	// cout << endl;




}


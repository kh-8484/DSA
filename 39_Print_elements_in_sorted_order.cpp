#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int main() {
//code
	int t;
	cin >> t;
	int n, *arr;
	for (int i = 0; i < t; i++) {
		cin >> n;
		arr = (int*)malloc(sizeof(int) * (n * n));

		for (int j = 0; j < (n * n); j++)
			cin >> arr[j];

		sort(arr, arr + (n * n));

		for (int j = 0; j < (n * n); j++)
			cout << arr[j] << " ";
		cout << "\n";
	}
	return 0;
}
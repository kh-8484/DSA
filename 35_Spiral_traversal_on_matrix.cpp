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
		int n, m;

		cin >> n >> m;

		int arr[n][m];


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}

		int row_start = 0, row_end = n - 1, col_start = 0, col_end = m - 1;

		while (row_start <= row_end && col_start <= col_end) {
			//for row start
			for (int col = col_start; col <= col_end; col++) {
				cout << arr[row_start][col] << " ";
			}
			row_start++;

			//for column end
			for (int row = row_start; row <= row_end; row++) {
				cout << arr[row][col_end] << " ";
			}
			col_end--;

			//for row end
			for (int col = col_end; col >= col_start; col--) {
				cout << arr[row_end][col] << " ";
			}
			row_end--;

			//for column start
			for (int row = row_end; row >= row_start; row--) {
				cout << arr[row][col_start] << " ";
			}
			col_start++;
		}

		// 	for (int i = 0; i < n; i++) {
		// 		for (int j = 0; j < m; j++) {
		// 			cout << arr[i][j] << " ";
		// 		}
		//      cout << endl;
		// }

	}

}

////////


class Solution
{
public:
	vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)
	{
		// code here
		vector<int> a;
		int row_start = 0, row_end = r - 1, col_start = 0, col_end = c - 1;

		while (row_start <= row_end && col_start <= col_end) {
			//for row start
			for (int col = col_start; col <= col_end; col++) {
				a.push_back(matrix[row_start][col]);
			}
			row_start++;

			//for column end
			for (int row = row_start; row <= row_end; row++) {
				a.push_back(matrix[row][col_end]);
			}
			col_end--;

			//for row end
			if (row_start <= row_end) {
				for (int col = col_end; col >= col_start; col--) {
					a.push_back(matrix[row_end][col]);
				}
				row_end--;
			}
			//for column start
			if (col_start <= col_end) {
				for (int row = row_end; row >= row_start; row--) {
					a.push_back(matrix[row][col_start]);
				}
				col_start++;
			}
		}

		return a;
	}
};

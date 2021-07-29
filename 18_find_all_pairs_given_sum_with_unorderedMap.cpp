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
		int n, k;

		cin >> n >> k;

		int arr[n];


		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		unordered_map <int, int> m;

		for (int i = 0; i < n; i++) {
			m[arr[i]]++;
		}

		int twice_count = 0;

		for (int i = 0; i < n; i++) {
			twice_count += m[k - arr[i]];

			if ((k - arr[i]) == arr[i]) {
				twice_count--;
			}
		}


		cout << twice_count / 2 << endl;

		// for (int i = 0; i < n; i++) {
		// 	cout << arr[i] << " ";
		// }

//        class Solution{
// public:
//     int getPairsCount(int arr[], int n, int k) {
//         // code here
//         int c=0;
//         unordered_map<int, int> m;
//         for(int i=0; i<n; i++){
//             int x = k - arr[i];
//             if(m[x] == 0){
//                 m[arr[i]]++;
//             }else{
//                 c+=m[x];
//                 m[arr[i]]++;
//             }

//         }
//         return c;
//     }
// };

	}

}


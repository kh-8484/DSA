#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int ans = -1;
		// unordered_map<int, int>m;
		// for(int i=0; i<n; i++){
		//     m[arr[i]] = 1;
		// }
		// for(int i=0; i<n; i++){
		//     if(m[arr[i]+d]){
		//         ans = 1;
		//         break;
		//     }
		// }
		sort(arr, arr + n);
		for (int i = 0; i < n; i++) {
			int idx = upper_bound(arr + i + 1, arr + n, d + arr[i]) - arr - 1;
			if (arr[idx] - arr[i]  == d) {
				ans = 1;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	//code here
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = 0, open = 0, close = 0, fault = 0;

		for (int i = 0; i <= n; i++) {
			if (s[i] == ']') {
				close++;
				fault = close - open;
			}
			else {
				open++;
				if (fault > 0) {
					ans += fault;
					fault--;
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}
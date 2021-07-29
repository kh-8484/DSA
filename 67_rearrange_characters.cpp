#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		unordered_map<int, int> m;
		int max = 0;
		int n = s.length();
		for (int i = 0; i < n; i++) {
			m[s[i]]++;

			if (max < m[s[i]]) {
				max = m[s[i]];
			}
		}

		if (max <= n - max + 1) {
			cout << "1" << endl;
		}
		else {
			cout << "0" << endl;
		}
	}
	return 0;
}
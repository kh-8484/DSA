#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		unordered_map<char, int> m;
		set<char> st;

		for (int i = 0; i < s.length(); i++) {
			st.insert(s[i]);  //store only distinct(unique) character
		}

		int n = st.size();
		int i = 0, j = 1, c = 0;
		m[s[i]]++;   // stores first char & its frequecy
		c++;       // count++

		int mi = INT_MAX;

		while (i <= j && j < s.length()) {
			if (c < n) { //expand window if count < n (distinct Char)
				if (m[s[j]] == 0) c++;
				m[s[j]]++;
				j++;
			}
			else if (c == n) { // shrinks window from first to last
				mi = min(mi, j - i); //if count == n (distinct char)
				if (m[s[i]] == 1) c--;
				m[s[i]]--;
				i++;
			}
		}
		// this loop is again used because in the upper loop it can end
		// at expand window
		while (c == n) {
			mi = min(mi, j - i); //minimum window length
			if (m[s[i]] == 1) c--;
			m[s[i]]--;
			i++;
		}

		cout << mi << endl;
	}
	return 0;
}
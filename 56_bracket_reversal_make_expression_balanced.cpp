#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	//code here
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (s.length() & 1) cout << "-1" << endl;
		else {
			stack<char> st;
			int c = 0, c2 = 0; //c2="{" & c="}"
			for (int i = 0; i < s.length(); i++) {
				char ch = s[i];
				if (ch == '{') {
					st.push(ch);
					c2++;
				}
				else if (ch == '}' && !st.empty() && st.top() == '{') {
					st.pop();
					c2--;
				}
				else {
					c++;
				}
			}
			if (c & 1)  c = (c / 2) + 1;
			else c = c / 2;
			if (c2 & 1) c2 = (c2 / 2) + 1;
			else c2 = c2 / 2;
			cout << c + c2 << endl;
		}
	}
	return 0;
}
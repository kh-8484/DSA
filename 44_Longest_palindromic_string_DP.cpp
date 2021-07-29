#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void printSubStr(string str, int low, int high)
{
	for (int i = low; i <= high; ++i)
		cout << str[i];
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	int T;

	cin >> T;

	while (T--) {
		string s;

		cin >> s;

		int n = s.size();

		// table[i][j] will be false if substring
		// str[i..j] is not palindrome.
		// Else table[i][j] will be true
		bool table[n][n];
		memset(table, 0, sizeof(table));

		int maxLength = 1;

		// All substrings of length 1
		// are palindromes
		for (int i = 0; i < n; i++) {
			table[i][i] = true;
		}

		// check for sub-string of length 2.
		int start = 0;
		for (int i = 0; i < n - 1; ++i) {
			if (s[i] == s[i + 1]) {
				table[i][i + 1] = true;
				start = i;
				maxLength = 2;
			}
		}

		// Check for lengths greater than 2.
		// k is length of substring
		for (int k = 3; k <= n; ++k) {
			// Fix the starting index
			for (int i = 0; i < n - k + 1; ++i) {
				// Get the ending index of substring from
				// starting index i and length k
				int j = i + k - 1;

				// checking for sub-string from ith index to
				// jth index iff str[i+1] to str[j-1] is a
				// palindrome
				if (table[i + 1][j - 1] && s[i] == s[j]) {
					table[i][j] = true;

					if (k > maxLength) {
						start = i;
						maxLength = k;
					}
				}
			}
		}

		printSubStr(s, start, start + maxLength - 1);
	}

}


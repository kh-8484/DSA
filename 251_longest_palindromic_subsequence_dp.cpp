#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int lps(string &s, int i, int j) {
	if (i == j) {
		return 1;
	}
	if (i > j) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (s[i] == s[j]) {
		return dp[i][j] = lps(s, i + 1, j - 1) + 2;
	}

	return dp[i][j] = max(lps(s, i, j - 1), lps(s, i + 1, j));
}

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	dp[n][n];
	memset(dp, -1, sizeof dp);
	cout << lps(s, 0, n - 1);

	return 0;
}
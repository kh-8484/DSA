class Solution
{
public:
	//Function to find the length of longest common subsequence in two strings.
	int lcs(int x, int y, string s1, string s2)
	{
		//using dp[][] array to store length of LCS.
		int dp[1001][1001];

		//Following steps build dp[x+1][y+1] in bottom up fashion. Note that
		//dp[i][j] contains length of LCS of s1[0..i-1] and s2[0..j-1].
		for (int i = 0; i <= x; i++)
		{
			for (int j = 0; j <= y; j++)
			{
				//if i or j is 0, we mark dp[i][j] as 0.
				if (i == 0 || j == 0)
					dp[i][j] = 0;

				//else if the current char in both strings are equal, we add 1
				//to the output we got without including these both characters.
				else if (s1[i - 1] == s2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;

				//else s1[i-1]!=s2[j-1] so we check the max output which
				//comes from s1 or s2 without considering current character.
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}

		//returning the result.
		return dp[x][y];
	}
};


class Solution
{
public:
	//Function to find the length of longest common subsequence in two strings.
	int dp[1001][1001];
	int solve(int x, int y, string &s1, string &s2) {
		if (x == -1 || y == -1) return 0;
		if (dp[x][y] != -1) return dp[x][y];
		if (s1[x] == s2[y]) return dp[x][y] = 1 + solve(x - 1, y - 1, s1, s2);
		int a = solve(x - 1, y, s1, s2);
		int b = solve(x, y - 1, s1, s2);
		return dp[x][y] = max(a, b);
	}
	int lcs(int x, int y, string s1, string s2)
	{
		// your code here
		memset(dp, -1, sizeof dp);
		return solve(x - 1, y - 1, s1, s2);
	}
};


// Space optimized C++ implementation
// of LCS problem
#include<bits/stdc++.h>
using namespace std;

// Returns length of LCS
// for X[0..m-1], Y[0..n-1]
int lcs(string &X, string &Y)
{

	// Find lengths of two strings
	int m = X.length(), n = Y.length();

	int L[2][n + 1];

	// Binary index, used to
	// index current row and
	// previous row.

	for (int i = 0; i <= m; i++)
	{



		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[i % 2][j] = 0;

			else if (X[i - 1] == Y[j - 1])
				L[i % 2][j] = L[(i + 1) % 2][j - 1] + 1;

			else
				L[i % 2][j] = max(L[(i + 1) % 2][j],
				                  L[i % 2][j - 1]);
		}
	}

	// Last filled entry contains
	// length of LCS
	// for X[0..n-1] and Y[0..m-1]
	return L[i % 2][n];
}

// Driver code
int main()
{
	string X = "AGGTAB";
	string Y = "GXTXAYB";

	printf("Length of LCS is %d\n", lcs(X, Y));

	return 0;
}

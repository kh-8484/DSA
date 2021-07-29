#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int dp[1001][1001];

int solve(string p, string s, int i, int j) {
    if (i == -1 && j == -1) {
        return 1;
    }

    if (j == -1) { // if string reaches end and pattern remains so check for *
        for (int k = 0; k < i; k++) {
            if (p[k] != '*') {
                return 0;
            }
        }
        return 1;
    }

    if (i == -1) { //if pattern reaches end and string is remaining so return 0
        return 0;
    }

    if (dp[i][j] != -1) { //memoization
        return dp[i][j];
    }

    if (p[i] == s[j] || p[i] == '?') { // a == a  or if pattern consist of ?
        return dp[i][j] = solve(p, s, i - 1, j - 1); //return length -1 of both
    }

    if (p[i] == '*') {
        int op1 = solve(p, s, i - 1, j); // decrease length of pattern by 1
        int op2 = solve(p, s, i, j - 1); // decrease length of string by 1
        return dp[i][j] = op1 || op2;
    }
    return dp[i][j] = 0; //both char dosen't match
}

int main() {
    //code
    int t;
    cin >> t;
    while (t--) {
        string p, s;
        cin >> p >> s;
        memset(dp, -1, sizeof(dp));
        int x = solve(p, s, p.length() - 1, s.length() - 1);

        if (x == 1) cout << "Yes" << endl;
        else  cout << "No" << endl;
    }
    return 0;
}
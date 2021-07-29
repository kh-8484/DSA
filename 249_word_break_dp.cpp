// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> dict;
        for (int i = 0; i < n; i++) {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        cout << wordBreak(line, dict) << "\n";
    }
}
// } Driver Code Ends


//User function template for C++

// A : given string to search
// B : vector of available strings
unordered_map<string, int> dp;

int solve(string s, vector<string> &b) {
    int sz = s.length();
    if (sz == 0) return 1;
    if (dp[s] != 0) return dp[s];

    for (int i = 1; i <= sz; i++) {
        int f = 0;
        string ss = s.substr(0, i);
        for (int j = 0; j < b.size(); j++) {
            if (ss.compare(b[j]) == 0) {
                f = 1;
                break;
            }
        }
        if (f == 1 && solve(s.substr(i, sz), b) == 1) return dp[s] = 1;
    }
    return dp[s] = -1;
}


int wordBreak(string A, vector<string> &B) {
    //code here
    int x = solve(A, B);
    if (x == 1) {
        return 1;
    }
    else {
        return 0;
    }
}
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int kadane(vector<int> a, int n) {
        int maxi = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum > maxi) maxi = sum;
            if (sum < 0) sum = 0;
        }
        return maxi;
    }
    int maximumSumRectangle(int r, int c, vector<vector<int>> mat) {
        // code here
        int ma = INT_MIN;
        for (int i = 0; i < r; i++) {
            vector<int> ans(c);
            for (int j = i; j < r; j++) {
                for (int col = 0; col < c; col++) {
                    ans[col] += mat[j][col];
                }
                ma = max(ma, kadane(ans, c));
            }
        }
        return ma;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends
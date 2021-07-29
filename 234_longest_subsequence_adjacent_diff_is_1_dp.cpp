// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
	int longestSubsequence(int n, int a[])
	{
		// code here
		// int dp[n];
		// for(int i=0; i<n; i++) dp[i] = 1;
		// for(int i=1; i<n; i++){
		//     for(int j=0; j<i; j++){
		//         if(abs(a[j]-a[i]) == 1){
		//             dp[i] = max(dp[i], dp[j]+1);
		//         }
		//     }
		// }
		// int ans=0;
		// for(int i=0; i<n; i++){
		//     ans = max(ans, dp[i]);
		// }
		// return ans;
		unordered_map<int, int> m;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int l = 0;
			if (m[a[i] - 1]) l = m[a[i] - 1];
			if (m[a[i] + 1] && m[a[i] + 1] > l) l = m[a[i] + 1]; //checking l is >
			//l is update in m[a[i]-1]
			m[a[i]] = l + 1;
			ans = max(ans, m[a[i]]);
		}
		return ans;
	}
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--) {
		int N;
		cin >> N;
		int A[N];
		for (int i = 0; i < N; i++)
			cin >> A[i];

		Solution ob;
		cout << ob.longestSubsequence(N, A) << endl;
	}
	return 0;
}  // } Driver Code Ends
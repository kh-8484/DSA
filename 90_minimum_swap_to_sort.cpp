// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
public:



	int minSwaps(vector<int>&nums) {
		// Code here
		int count = 0;
		int n = nums.size();
		vector<pair<int, int> > v(n);
		for (int i = 0; i < n; i++) {
			v[i] = {nums[i], i};
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < n; i++) {
			if (v[i].second == i) {
				continue;
			}
			else {
				count++;
				swap(v[i], v[v[i].second]);
				i--; //for checking swap has been done correctly or not
			}
		}
		return count;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int>nums(n);
		for (int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() + 1; i++) {
			if (nums[i] == nums[i + 1]) {
				return nums[i];
			}
		}
		return -1;
	}

	int main() {
#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("error.txt", "w", stderr);
		freopen("output.txt", "w", stdout);
#endif
		vector<int> nums;

		for (int i = 0; i < ; ++i)
		{
			/* code */
		}
	}
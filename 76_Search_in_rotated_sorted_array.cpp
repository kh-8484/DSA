class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1 && nums[0] == target) {
            return 0;
        }
        int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
                ans = i;
        }
        if (ans == -1) {
            return -1;
        }
        else {
            return ans;
        }
    }
};
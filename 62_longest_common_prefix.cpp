class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mi = INT_MAX;
        if (strs.size() == 0) return "";
        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            int j = 0, k = 0, a = 0;
            while (j < prefix.size() && k < strs[i].size()) {
                if (prefix[j] == strs[i][k]) {
                    a++;
                }
                else {
                    break;
                }
                j++;
                k++;
            }
            mi = min(mi, a);
        }
        return prefix.substr(0, mi);
    }
};
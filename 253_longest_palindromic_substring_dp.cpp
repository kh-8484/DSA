class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int best = 1;               // length of best string palindrome
        int st = 0;                 // starting index of our best string palindrome


        // for handling odd length palindrome

        for (int i = 0; i < n; i++)
        {
            int len = 1;           // because every single character will be a palindrome
            int j = i - 1;        // maintaing ith character as middle of our palindromic string,
            int k = i + 1;        // we start checking for further left and right side.

            while (j >= 0 && k < n && s[j] == s[k])
            {
                j--;
                k++;
                len = len + 2;
            }

            if (len > best)
            {
                best = len;
                st = j + 1;
            }
        }

        // similarly checking for even length palindromic substring.

        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                int len = 2;       // since we are taking two elements as middle , we start our length as 2.

                int j = i - 2;     // remaing steps are similar as for odd length palindrome.
                int k = i + 1;

                while (j >= 0 && k < n && s[j] == s[k])
                {
                    j--;
                    k++;
                    len = len + 2;
                }

                if (len > best)
                {
                    best = len;
                    st = j + 1;
                }
            }
        }

        return s.substr(st, best);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        bool dp[n][n];
        //int st, end;
        int len = 0;
        for (int g = 0; g < n; g++) {
            for (int i = 0, j = g; j < n; i++, j++) {
                if (g == 0) dp[i][j] = true;
                else if (g == 1) {
                    if (s[i] == s[j]) dp[i][j] = true;
                    else dp[i][j] = false;
                }
                else {
                    if (s[i] == s[j] && dp[i + 1][j - 1] == true) {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = false;
                    }
                }
                if (dp[i][j]) {
                    // st=i;
                    // end=j;
                    len = g + 1;
                }
            }
        }
        return s.substr(st, end);
    }
};
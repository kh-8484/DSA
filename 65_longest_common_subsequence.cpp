// { Driver Code Starts
#include<bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t, n, k, x, y;

    cin >> t;
    while (t--)
    {
        cin >> x >> y;      // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2;    // Take both the string as input

        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends


// function to find longest common subsequence

int lcs(int x, int y, string s1, string s2) {

    // your code here
    int dp[x + 1][y + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (i == 0 || j == 0) {
                continue;
            }
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[x][y];
}


// memoization in recursive
// it return prfevious ans and it should be placed in recursive function
// if(memo[m][n]!=0){
//             return memo[m][n];
//         }

// using recursion
// public class Solution {
//     public int LCS(String s1,String s2){
//         if(s1==null||s2==null){
//             return 0;
//         }
//         return generateLCS(s1,s2,s1.length()-1,s2.length()-1);
//     }

//     private int generateLCS(String s1,String s2,int m,int n){
//         if(m<0||n<0){
//             return 0;
//         }
//         int res=0;
//         int memo[][] = new int[m+1][n+1];
//         if(memo[m][n]!=0){
//             return memo[m][n];
//         }
//         if(s1.charAt(m)==s2.charAt(n)){
//             res=1+generateLCS(s1,s2,m-1,n-1);
//             memo[m][n]=res;
//         }else{
//             return Math.max(generateLCS(s1,s2,m-1,n),generateLCS(s1,s2,m,n-1));
//         }
//         return memo[m][n];

//     }

//     public static void main(String[] args) {
//         System.out.println(new Solution().LCS("ABCDZ","AEBDZ"));
//     }
// }
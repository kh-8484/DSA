class Solution {
public:
  int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int dp[n];
//         for(int i=0; i<n; i++){
//             dp[i]=0;
//         }
//         int ma = prices[n-1];
//         int mi = prices[0];
//         for(int i=n-2; i>=0; i--){
//            if(ma < prices[i]){
//               ma = prices[i];
//            }
//            dp[i] = max(dp[i+1], ma - prices[i]);
//         }

//         for(int i=1; i<n; i++){
//            if(mi > prices[i]){
//                mi = prices[i];
//            }
//            dp[i] = max(dp[i-1], dp[i] + (prices[i] - mi));
//         }
//         return dp[n-1];
    int buy1 = INT_MAX, buy2 = INT_MAX;
    int profit1 = 0, profit2 = 0;
    int n = prices.size();
    for (int i = 0; i < n; i++) {
      buy1 = min(prices[i], buy1);
      profit1 = max(profit1, prices[i] - buy1);
      buy2 = min(buy2, prices[i] - profit1);
      profit2 = max(profit2, prices[i] - buy2);
    }
    return profit2;
  }
};

#include <iostream>
using namespace std;

int main()
{
  int price[] = { 2, 30, 15, 10, 8, 25, 80 };
  int n = 7;

  // adding array
  int profit = 0;

  // Initializing variable
  // valley-peak approach
  /*
          80
          /
    30     /
  / \    25
  / 15   /
  /  \   /
  2  10 /
      \ /
        8
  */
  for (int i = 1; i < n; i++)
  {

    // traversing through array from (i+1)th
    // position
    int sub = price[i] - price[i - 1];
    if (sub > 0)
      profit += sub;
  }

  cout << "Maximum Profit=" << profit;
  return 0;
}

// This code is contributed by RohitOberoi.

// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>

using namespace std;

#define ll long long
ll findSubarray(vector<ll> , int );

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n; //input size of array

    vector<ll> arr(n, 0);

    for (int i = 0; i < n; i++)
      cin >> arr[i]; //input array elements

    cout << findSubarray(arr, n) << "\n";
  }
  return 0;
}// } Driver Code Ends


//User function template for C++

// arr : given array
// n : size of the given array

ll findSubarray(vector<ll> arr, int n ) {
  //code here
  int count = 0, sum = 0;
  unordered_map<int, int> m;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    if (sum == 0) {
      count++;
    }
    if (m[sum]) {
      count += m[sum];
    }
    m[sum]++;
  }
  return count;
}

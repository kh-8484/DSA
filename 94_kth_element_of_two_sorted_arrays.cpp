// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// using binary search
// int kth(int *arr1, int *arr2, int *end1, int *end2, int k)
// {
//     if (arr1 == end1)
//         return arr2[k];
//     if (arr2 == end2)
//         return arr1[k];
//     int mid1 = (end1 - arr1) / 2;
//     int mid2 = (end2 - arr2) / 2;
//     if (mid1 + mid2 < k)
//     {
//         if (arr1[mid1] > arr2[mid2])
//             return kth(arr1, arr2 + mid2 + 1, end1, end2,
//                 k - mid2 - 1);
//         else
//             return kth(arr1 + mid1 + 1, arr2, end1, end2,
//                 k - mid1 - 1);
//     }
//     else
//     {
//         if (arr1[mid1] > arr2[mid2])
//             return kth(arr1, arr2, arr1 + mid1, end2, k);
//         else
//             return kth(arr1, arr2, end1, arr2 + mid2, k);
//     }
// }

// int kthElement(int arr1[], int arr2[], int n, int m, int k)
// {
//     return kth(arr1, arr2, arr1+n, arr2+m, k-1);
// }


class Solution {
public:
  int kthElement(int arr1[], int arr2[], int n, int m, int k)
  {
    int i = 0, j = 0, x = 0;
    while (i < n && j < m) {
      if (arr1[i] < arr2[j]) {
        x++;
        if (x == k) {
          return arr1[i];
        }
        i++;
      }
      else {
        x++;
        if (x == k) {
          return arr2[j];
        }
        j++;
      }
    }
    while (i < n) {
      x++;
      if (x == k) {
        return arr1[i];
      }
      i++;
    }
    while (j < m) {
      x++;
      if (x == k) {
        return arr2[j];
      }
      j++;
    }
  }
};

// { Driver Code Starts.

// Driver code
int main()
{
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int arr1[n], arr2[m];
    for (int i = 0; i < n; i++)
      cin >> arr1[i];
    for (int i = 0; i < m; i++)
      cin >> arr2[i];

    Solution ob;
    cout << ob.kthElement(arr1, arr2, n, m, k) << endl;
  }
  return 0;
}  // } Driver Code Ends
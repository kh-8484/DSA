// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {

public:

    static bool comp(int a, int b) {
        return __builtin_popcount(a) > __builtin_popcount(b);
        // __builtin_popcount(a) it gives total no of set bits it means count 1
    }

    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        stable_sort(arr, arr + n, comp);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
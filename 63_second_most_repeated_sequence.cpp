#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends




class Solution
{
public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string, int> mp;
        string str = "";

        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }

        int max1 = INT_MIN;
        int max2 = INT_MIN;

        for (auto i : mp) {
            max1 = max(max1, i.second);
        }

        for (auto i : mp) {
            if (i.second != max1) {
                max2 = max(max2, i.second);
            }
        }

        for (auto i : mp) {
            if (i.second == max2) {
                str = i.first;
                break;
            }
        }
        return str;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
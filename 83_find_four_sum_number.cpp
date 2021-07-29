// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > fourSum(vector<int> &a, int k);

// Position this line where user code will be pasted.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int> > ans = fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// arr[] : int input array of integers
// k : the quadruple sum required
vector<vector<int> > fourSum(vector<int> &arr, int k) {
    // Your code goes here
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    int left, right;
    int n = arr.size();
    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            left = j + 1;
            right = n - 1;

            while (left < right) {
                vector<int> res1;
                if (arr[i] + arr[j] + arr[left] + arr[right] == k) {
                    res1.push_back(arr[i]);
                    res1.push_back(arr[j]);
                    res1.push_back(arr[left]);
                    res1.push_back(arr[right]);
                    res.push_back(res1);
                    left++;
                    right--;
                }
                else if (arr[i] + arr[j] + arr[left] + arr[right] < k) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}
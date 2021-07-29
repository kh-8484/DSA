#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(int arr[], int n, int x, int tog) {
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < x) {
            low = mid + 1;
        }
        else if (arr[mid] > x) {
            high = mid - 1;
        }
        else {
            ans = mid;
            if (tog == -1) high = mid + tog;
            else low = mid + tog;
        }
    }
    return ans;
}

int main() {
    //code
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        int f, l;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int idx1 = solve(arr, n, x, -1);
        int idx2 = solve(arr, n , x, 1);

        if (idx1 == -1) cout << -1 << endl;
        else cout << idx1 << " " << idx2 << endl;

        //     int idx1 = lower_bound(arr, arr+n, x) - arr;
        //     int idx2 = upper_bound(arr, arr+n, x) - arr - 1;
        //     if(idx1 == n) cout << -1 << endl;
        // else cout << idx1 << " " << idx2 <<endl;
    }
    return 0;
}
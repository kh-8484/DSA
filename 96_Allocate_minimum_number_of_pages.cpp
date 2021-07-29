// { Driver Code Starts
// Initial template for C++


#include<bits/stdc++.h>
using namespace std;


int findPages(int arr[], int n, int m);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        cout << findPages(A, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//User function template in C++
bool solve(int arr[], int n, int mid, int m) {
    int sum = 0;
    int student = 1;
    for (int i = 0; i < n; i++) {

        if (arr[i] > mid) return false;

        if (sum + arr[i] > mid) {
            sum = arr[i];
            student++;
            if (student > m) return false;
        }
        else sum += arr[i];
    }
    return true;
}

int findPages(int arr[], int n, int m) {
    //code here
    int lb = 0, s = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        s += arr[i];
    }

    int ub = s;

    while (lb <= ub) {
        int mid = (lb + ub) / 2;
        if (solve(arr, n, mid, m)) {
            ans = mid;
            ub = mid - 1;
        }
        else {
            lb = mid + 1;
        }
    }
    return ans;
}


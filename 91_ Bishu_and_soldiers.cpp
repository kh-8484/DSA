#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int prev_sum[n + 1];
    prev_sum[0] = 0;

    for (int i = 1; i <= n; i++) {
        prev_sum[i] = prev_sum[i - 1] + arr[i - 1];
    }

    int q;
    cin >> q;

    while (q--) {
        int x; cin >> x;
        int idx = upper_bound(arr, arr + n, x) - arr;
        cout << idx << " " << prev_sum[idx] << endl;
    }

    return 0;
}
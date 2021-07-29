bool subArrayExists(int arr[], int n)
{
    //Your code here
    int sum = 0, f = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0 || m[sum] || arr[i] == 0) {
            f = 1;
            // 1 -- YES && 0 -- NO
            break;
        } else {
            m[sum] = 1;
        }
    }
    if (f == 1) {
        return 1;
    } else {
        return 0;
    }
}
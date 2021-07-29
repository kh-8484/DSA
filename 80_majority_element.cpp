// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int arr[], int size)
{
    // your code here
    int m = arr[0], count = 1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == m) {
            count++;
        }
        else {
            count --;
        }
        if (count == 0) {
            m = arr[i];
            count = 1;
        }
    }
    int c = 0;
    for (int i = 0; i < size; i++) {
        if (m == arr[i]) {
            c++;
        }
    }
    if (size / 2 < c) {
        return m;
    }
    else {
        return -1;
    }
}

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}
// } Driver Code Ends
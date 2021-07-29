// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {


public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
		// Your code goes here
		int count = 0;
		// brute force
		// for(int i=0; i<n-2; i++){
		//     for(int j=i+1; j<n-1; j++){
		//         for(int k=j+1; k<n; k++){
		//             if(arr[i]+arr[j]+arr[k]<sum){
		//                 count++;
		//             }
		//         }
		//     }
		// }
		sort(arr, arr + n);
		for (int k = 0; k < n - 2; k++) {
			int i = k + 1;
			int j = n - 1;
			while (i < j) {
				int s = arr[k] + arr[i] + arr[j];
				if (s < sum) {
					count += (j - i);
					i++;
				}
				else {
					j--;
				}
			}
		}
		return count;
	}


};

// { Driver Code Starts.

int main()
{


	int t;
	cin >> t;
	while (t--)
	{
		int n;
		long long sum;
		cin >> n >> sum;
		long long arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}




		Solution ob;
		cout << ob.countTriplets(arr, n, sum) ;


		cout << "\n";

	}
	return 0;
}

// } Driver Code Ends
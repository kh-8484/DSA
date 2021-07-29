// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>&, int );

// your code will be pasted here

int main()
{
	int t;  // number of test cases
	cin >> t;
	while (t--)
	{
		int n;  // size of the array
		cin >> n;
		vector<long long int> arr(n), vec(n);

		for (int i = 0; i < n; i++) // input the array
		{
			cin >> arr[i];
		}

		vec = productExceptSelf(arr, n);  // function call

		for (int i = 0; i < n; i++) // print the output
		{
			cout << vec[i] << " ";
		}
		cout << endl;
	}
	return 0;
}// } Driver Code Ends


//User function template for C++

// nums: given vector
// return the Product vector P that hold product except self at each index
vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
	//code here
	//with division
	// long long int prod=1;
	// int zero_flag=0;
	// for(int i=0; i<n; i++){
	//     if(nums[i]!=0){
	//       prod *= nums[i];
	//     }
	//     else{
	//       zero_flag++;
	//     }
	// }
	// if(zero_flag>1){
	//     for(int i=0; i<n; i++){
	//         nums[i]=0;
	//     }
	//     return nums;
	// }
	// if(zero_flag==1){
	//     for(int i=0; i<n; i++){
	//         if(nums[i]==0){  // if nums[0] so put product to that element
	//             nums[i]=prod;
	//         }
	//         else{
	//             nums[i]=0;   // else put 0
	//         }
	//     }
	//     return nums;
	// }
	// for(int i=0; i<n; i++){
	//     nums[i] = prod/nums[i];
	// }
	// return nums;

	// without divsion method
	vector<long long int> l(n), r(n);

	l[0] = 1;
	r[n - 1] = 1;

	for (int i = 1; i < n; i++) {
		l[i] = l[i - 1] * nums[i - 1];
	}
	for (int i = n - 2; i >= 0; i--) {
		r[i] = r[i + 1] * nums[i + 1];
	}
	for (int i = 0; i < n; i++) {
		nums[i] = l[i] * r[i];
	}
	return nums;
}

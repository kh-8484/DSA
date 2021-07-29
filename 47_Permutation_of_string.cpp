// #include <bits/stdc++.h>
// using namespace std;


// // Function to print permutations of string
// // This function takes three parameters:
// // 1. String
// // 2. Starting index of the string
// // 3. Ending index of the string.
// void permute(string a, int l, int r)
// {
//     // Base case
//     if (l == r)
//         cout<<a<< " ";
//     else
//     {
//         // Permutations made
//         for (int i = l; i <= r; i++)
//         {

//             // Swapping done
//             swap(a[l], a[i]);

//             // Recursion called
//             permute(a, l+1, r);

//             //backtrack
//             swap(a[l], a[i]);
//         }
//     }
// }

// // Driver Code
// int main()
// {
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("error.txt", "w", stderr);
// freopen("output.txt", "w", stdout);
// #endif
//     int T;
//     cin >> T;
//     while(T--){
//       string str;
//       cin >> str;
//       int n = str.size();
//       permute(str, 0, n-1);
//       cout << endl;
//     }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		do
		{
			std::cout << s << " ";
		}
		while ( std::next_permutation(s.begin(), s.end()) );
		cout << endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// return the smallest window in S with all the characters of P
// if no such window exists, return "-1"
string smallestWindow (string str, string pat) {
	// Your code here
	int len_s = str.length();
	int len_p = pat.length();

	if (len_s < len_p) {
		return "-1";
	}

	int hash_pat[256] = {0};
	int hash_str[256] = {0};

	for (int i = 0; i < len_p; i++) {
		hash_pat[pat[i]]++;
	}
	int start = 0, start_index = -1, min_len = INT_MAX;
	int count = 0;

	for (int j = 0; j < len_s; j++) {

		hash_str[str[j]]++;

		// If string's char matches with pattern's char
		// then increment count
		if (hash_pat[str[j]] != 0 && hash_str[str[j]] <= hash_pat[str[j]]) {
			count++;
		}

		// if all the characters are matched
		if (count == len_p) {
			// Try to minimize the window i.e., check if
			// any character is occurring more no. of times
			// than its occurrence in pattern, if yes
			// then remove it from starting and also remove
			// the useless characters.
			while (hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0)
			{

				if (hash_str[str[start]] > hash_pat[str[start]])
					hash_str[str[start]]--;
				start++;
			}
			//update window size
			int len_window = j - start + 1;

			if (min_len > len_window) {
				min_len = len_window;
				start_index = start;
			}
		}
	}
	if (start_index == -1) {
		return "-1";
	}

	return str.substr(start_index, min_len);
}

// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		string pat;
		cin >> pat;

		cout << smallestWindow(s, pat) << endl;

	}
	return 0;
}  // } Driver Code Ends
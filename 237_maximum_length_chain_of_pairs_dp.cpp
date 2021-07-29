// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val {
	int first;
	int second;
};



int maxChainLen(struct val p[], int n);
int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		val p[n];
		for (int i = 0; i < n; i++)
		{
			cin >> p[i].first >> p[i].second;
		}

		cout << maxChainLen(p, n) << endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int maxChainLen(struct val p[], int n)
{
	//Your code here
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		v.push_back({p[i].first, p[i].second});
	}
	sort(v.begin(), v.end(), comp);
	int ans = 1, i = 0, j = 1, len = v.size();
	while (j < len) {
		if (v[i].second < v[j].first) {
			ans++;
			i = j;
			j++;
		}
		else {
			j++;
		}
	}
	return ans;
}

bool cmp(struct val p1, struct val p2)
{
	if (p1.first < p2.first)
		return 1;
	else if (p1.first == p2.first and p1.second < p2.second)
		return 1;
	return 0;
}
int dp[100001];
int maxChainLen(struct val p[], int n)
{
	sort(p, p + n, cmp);

	for (int i = 0; i < 10001; i++)
		dp[i] = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (p[i].first > p[j].second and dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

	int m = INT_MIN;
	for (int i = 0; i < n; i++)
		m = max(dp[i], m);

	return m;
}
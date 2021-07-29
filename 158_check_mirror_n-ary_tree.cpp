#include<bits/stdc++.h>
using namespace std;
#define MAX_NODES 16

bool isMirror(vector<stack<int>> tree1, vector<queue<int>> tree2) {
	for (int i = 0; i < tree1.size(); ++i) {
		stack<int> s = tree1[i];
		queue<int> q = tree2[i];

		while (s.empty() == false && q.empty() == false) {
			if (s.top() != q.front()) {
				return false;
			}

			s.pop();
			q.pop();
		}

		if (s.empty() == false || q.empty() == false) {
			return false;
		}
	}
	return true;
}

int main()
{
	int T, n, e;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> n >> e;

		int u[2 * e];
		int v[2 * e];

		for (int j = 0; j < 2 * e; ++j) {
			cin >> u[j];
		}
		for (int k = 0; k < 2 * e; ++k) {
			cin >> v[k];
		}

		vector<stack<int>> tree1(MAX_NODES);
		vector<queue<int>> tree2(MAX_NODES);

		for (int i = 0; i < 2 * e; ++i) {
			int m = i++;
			int n = i;
			tree1[u[m]].push(u[n]);
		}

		for (int i = 0; i < 2 * e; ++i) {
			int m = i++;
			int n = i;
			tree2[v[m]].push(v[n]);
		}

		if (isMirror(tree1, tree2) == true) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
	return 0;
}
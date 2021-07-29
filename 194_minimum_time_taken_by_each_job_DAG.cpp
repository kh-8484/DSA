#include<bits/stdc++.h>
using namespace std;

int main() {
	int v, e;
	cin >> v >> e;

	vector<int> g[v + 1];
	vector<int> indegree(v + 1, 0);
	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		indegree[y]++;
	}

	vector<int> ans(v + 1, 0);
	queue<int> q;

	for (int i = 0; i < v; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			ans[i] = 1;
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto it : g[node]) {
			indegree[it]--;
			if (indegree[it] == 0) {
				ans[it] = ans[node] + 1;
				q.push(it);
			}
		}
	}

	for (int i = 0; i < v; i++) cout << ans[i] << " ";

	return 0;
}
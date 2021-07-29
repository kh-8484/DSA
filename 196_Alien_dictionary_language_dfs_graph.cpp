// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    void dfs(int node, vector<vector<int>> &g, vector<int> &vis, string &ans) {
        vis[node] = 1;

        for (auto it : g[node]) {
            if (!vis[it]) {
                dfs(it, g, vis, ans);
            }
        }
        char ch = node + 'a';
        ans = ch + ans;
    }

    string findOrder(string dict[], int n, int k) {
        //code here
        vector<vector<int>> g(k);
        for (int i = 0; i < n - 1; i++) {
            string w1 = dict[i];
            string w2 = dict[i + 1];

            for (int j = 0; j < min(w1.length(), w2.length()); j++) {
                if (w1[j] != w2[j]) {
                    g[w1[j] - 'a'].push_back(w2[j] - 'a');
                    break;
                }
            }
        }
        vector<int> vis(k, 0);
        string ans = "";

        for (int i = 0; i < k; i++) {
            if (!vis[i]) {
                dfs(i, g, vis, ans);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //  cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if (f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
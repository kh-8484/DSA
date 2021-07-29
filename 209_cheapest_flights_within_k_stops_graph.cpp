class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (auto x : flights) {
            g[x[0]].push_back({x[1], x[2]});
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        pq.push(make_tuple(0, src, 0));

        vector<vector<int>> dp(n + 3, vector<int> (k + 3, -1));

        while (!pq.empty()) {
            auto [cost, u, stops] = pq.top();
            pq.pop();

            if (dst == u) return cost;
            if (k < stops) continue;
            if (dp[u][stops] != -1) continue;
            dp[u][stops] = cost;
            for (auto x : g[u]) {
                auto [v, w] = x;
                pq.push(make_tuple(cost + w, v, stops + 1));
            }
        }
        return -1;
    }
};
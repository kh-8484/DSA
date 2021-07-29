//DFS
class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& image, vector<vector<int>> vis, int x, int y, int oldColor, int newColor) {
        if (i<0 or j<0 or i >= x or j >= y) return;
        if (vis[i][j] or image[i][j] != oldColor) return;

        vis[i][j] = 1;
        image[i][j] = newColor;

        dfs(i + 1, j, image, vis, x, y, oldColor, newColor);
        dfs(i - 1, j, image, vis, x, y, oldColor, newColor);
        dfs(i, j + 1, image, vis, x, y, oldColor, newColor);
        dfs(i, j - 1, image, vis, x, y, oldColor, newColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int x = image.size();
        int y = image[0].size();
        vector<vector<int> > vis(x, vector<int> (y, 0));

        int oldColor = image[sr][sc];
        dfs(sr, sc, image, vis, x, y, oldColor, newColor);
        return image;
    }

};
//BFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        int startColor = image[sr][sc];
        if (startColor == newColor) return image;
        int e[4][2] = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
        image[sr][sc] = newColor;
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = r + e[k][0];
                int y = c + e[k][1];
                if (x >= 0 && y >= 0 && x < m && y < n && image[x][y] == startColor) {
                    image[x][y] = newColor;
                    q.push(make_pair(x, y));
                }
            }
        }
        return image;
    }
};
class Solution {
public:

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board[0].size();
        int steps = 0;
        queue<int> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        q.push(1);
        vis[n - 1][0] = true;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int x = q.front();
                q.pop();
                if (x == n * n) return steps;
                for (int k = 1; k <= 6; k++) {
                    if (k + x > n * n) break;
                    int* pos = findCoordinates(k + x, n);
                    int r = pos[0];
                    int c = pos[1];
                    if (vis[r][c] == true) continue;
                    vis[r][c] = true;
                    if (board[r][c] == -1) {
                        q.push(k + x);
                    }
                    else {
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
    int* findCoordinates(int curr, int n) {
        int arr[2];
        int r = (n - (curr - 1) / n) - 1;
        int c = (curr - 1) % n;
        if (r % 2 == n % 2) {
            arr[0] = r;
            arr[1] = n - 1 - c;
            return arr;
        }
        else {
            arr[0] = r;
            arr[1] = c;
            return arr;
        }
    }
};
#include<bits/stdc++.h>
#define int long long int
using namespace std;

int subsum(vector<int> a, int n) {
    int s = 0;
    int ma = 1;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        s = s + a[i];
        if (s == 0) {
            ma = max(ma, i + 1);
        }
        else if (m[s]) {
            ma = max(ma, i - m[s]);
        }
        else {
            m[s] = i; //m[s]=1;
        }
    }
    return ma;
}



int32_t main() {

    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int> > mat(r, vector<int>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> mat[i][j];
                mat[i][j] == 0 ? mat[i][j] = -1 : mat[i][j] = 1;
            }
        }
        int ma = INT_MIN;
        for (int i = 0; i < r; i++) {
            vector<int> ans(c);
            for (int j = i; j < r; j++) {
                for (int col = 0; col < c; col++) {
                    ans[col] += mat[j][col];
                }
                ma = max(ma, subsum(ans, c) * (j - i + 1));
            }
        }
        cout << ma << endl;

    }


    return 0;


}







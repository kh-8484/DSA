//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<string> > Anagrams(vector<string>& string_list) ;

// } Driver Code Ends


//User function Template for C++

vector<vector<string> > Anagrams(vector<string>& a)
{
    // Your Code Here
    map<string, vector<string> > m;
    for (int i = 0; i < a.size(); i++) {
        string s = a[i];
        sort(s.begin(), s.end());       // cat --> act,  tac --> act
        m[s].push_back(a[i]);          // act --> cat, act, tac
    }

    vector<vector<string> > ans(m.size());

    int idx = 0;
    for (auto x : m) {
        auto v = x.second;           // storing act --> cat, act, tac
        for (int i = 0; i < v.size(); i++) {
            ans[idx].push_back(v[i]);
        }
        idx++;
    }
    return ans;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        vector<vector<string> > result = Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends
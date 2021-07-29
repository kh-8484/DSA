#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;

namespace mp = boost:: multiprecision;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        mp::cpp_int res = 1;
        for (int i = 1; i <= n; i++)
            res = res * i;
        cout << res << endl;

    }
}
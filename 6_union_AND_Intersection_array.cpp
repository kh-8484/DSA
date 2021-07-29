#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin>>t;
    while(t--)
    {
        int n,m,c=0; cin>>n>>m; int a[n+m];
        for(int i=0;i<n+m;i++) cin>>a[i];
        sort(a, a+n+m);
        for(int i=0; i<n+m-1; i++){
            if(a[i] != a[i+1])
            {
                c++;
            }
        }
        cout<<c+1<<endl;
    }
	return 0;
}
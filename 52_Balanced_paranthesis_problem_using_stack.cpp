// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Function to return if the paranthesis are balanced or not
bool ispar(string x)
{
    // Your code here
    stack<char> s;
    char a;

    for (int i = 0; i < x.length(); i++) {
        if (x[i] == '(' || x[i] == '[' || x[i] == '{') {
            s.push(x[i]);
            continue;
        }
        if (s.empty()) {
            return false;
        }

        switch (x[i]) {
        case ')':
            a = s.top();
            s.pop();

            if (a == '{' || a == '[') {
                return false;
            }
            break;
        case '}':
            a = s.top();
            s.pop();

            if (a == '(' || a == '[') {
                return false;
            }
            break;
        case ']':
            a = s.top();
            s.pop();

            if (a == '(' || a == '{') {
                return false;
            }
            break;
        }
    }
    return (s.empty());
}


// { Driver Code Starts.

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        if (ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
}  // } Driver Code Ends
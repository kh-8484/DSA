#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        cout << "Enter string: ";
        string str;
        cin >> str;

        ll len = str.length(); //len variable stores length of string.
        ll lps[len]; //declare lps array.
        lps[0] = 0; //single charater case so length lps is 0.
        ll i, j;
        i = 1; //initialise index for comparison from 1.
        j = 0; //initial longest prefix suffix length.

        while (i < len) //check until i!=len of string.
        {
            //check current index character with character stored at j.
            if (str[i] == str[j])
            {
                j++; //increase length by one.
                lps[i] = j; //lps for current index is equal to j
                i++; //move forward.
            }
            else //if str[i]!=str[j]
            {
                //we search for that index which character matches
                //with the current character at index i.
                if (j != 0)
                    j = lps[j - 1];
                else {
                    lps[i] = 0; //if j==0 then lps[i]=0.
                    i++; //move forward.
                }
            }
        }
        cout << "Maximum length of proper prefix-suffix: ";
        cout << lps[len - 1] << "\n";
    }

    return 0;
}

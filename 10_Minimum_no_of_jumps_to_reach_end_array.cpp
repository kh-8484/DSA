#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int minimumjumps(int n){
    if(n<=1)            // If n is less than 1 no jumps are required.
        return 0;
    if(arr[0] == 0)     // If first element is 0, we can't jump to any point return -1
        return -1;
      
    int maxrange = arr[0];  // Define maxRange for first element (Greedy Approach)
    int steps = arr[0];     // Steps allowed from first element
    int jumps = 1;          // Number of jumps required
    
    for(int i = 1; i<n; ++i){
        
        if(i == n-1) return jumps;  // If we reached the end return the number of jumps
        maxrange = max(maxrange, i+arr[i]); // calculate maxrange by comparing the current max range from current value
        steps--;                            // reduce steps each time we are moving forward
        
        if(steps == 0){                     // If steps is 0
            ++jumps;                        // Increase the number of jumps
            if(i>= maxrange) return -1;     // If maxRange is less than equal to i we can't move further, return -1
            steps = maxrange - i;           // New Steps value is calculated as maxRange-i.
        }
     }
     return -1; 
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minimumjumps(n)<<endl;    // Function to calculate minimum number of jumps
    }
    return 0;
}
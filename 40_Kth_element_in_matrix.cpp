int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    //Your code here
    vector<int> v;                                                   // vector to store 2D matrix into 1D array
    for (int i = 0; i < n; i++)                            // traverse row wise
    {
        for (int j = 0; j < n; j++)                       // traverse column wise
        {
            v.push_back(mat[i][j]);                                  // push matrix element in vector of 1D
        }
    }
    priority_queue<int> pq;                                 // max heap because we need to find smallest and in max heap all greater element is popped out
    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i]);                                              // push element into heap
        if (pq.size() > k)                                         // whenever size of heap exceed we need to pop
        {
            pq.pop();                                              // pop operation in heap
        }
    }
    return pq.top();                                           // topmost element of heap will be Kth smallest ele
}

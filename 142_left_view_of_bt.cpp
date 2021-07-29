// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> leftView(struct Node *root);

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        vector<int> vec = leftView(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// A wrapper over leftViewUtil()
// void leftViewUtil(vector<int> &vec, struct Node *root, int level, int *max_level)
// {
//     // base case
//     if (root==NULL)  return;

//     // If this is the first node of its level
//     if (*max_level < level)
//     {
//         vec.push_back(root->data);
//         *max_level = level;
//     }

//     // Recur for left and right subtrees
//     leftViewUtil(vec,root->left, level+1, max_level);
//     leftViewUtil(vec,root->right, level+1, max_level);
// }

// // Function to get the left view
// vector<int> leftView(struct Node *root)
// {
//     int max_level = 0;
//     vector<int> vec;
//     // calling util function
//     leftViewUtil(vec,root, 1, &max_level);
//     return vec;
// }   recursive approach  < up >
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> ans;
    if (!root) {
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int s = q.size();  // storing size of current level
        ans.push_back(q.front()->data);  //store the data of first/left node
        while (s--) {
            Node *temp = q.front();
            q.pop();

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }

    return ans;
}

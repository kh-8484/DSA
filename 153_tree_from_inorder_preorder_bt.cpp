// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

Node *buildTree(int inorder[], int preorder[], int n);

void printPostOrder(Node *root)
{
	if (root == NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout << root->data << " ";
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int inorder[n], preorder[n];
		for (int i = 0; i < n; i++)
			cin >> inorder[i];
		for (int i = 0; i < n; i++)
			cin >> preorder[i];

		Node *root = buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout << endl;
	}
}
// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
int idx = 0;
unordered_map<int, int> m;

Node* solve(int in[], int pre[], int lb, int ub) {
	if (lb > ub) return NULL;

	Node *res = new Node(pre[idx++]);

	if (lb == ub) return res;

	int mid = m[res->data];

	res->left = solve(in, pre, lb, mid - 1);
	res->right = solve(in, pre, mid + 1, ub);

	return res;
}

Node* buildTree(int in[], int pre[], int n)
{
	//add code here.
	idx = 0;
	m.clear();
	for (int i = 0; i < n; i++) m[in[i]] = i;
	Node *root = solve(in, pre, 0, n - 1);
	return root;
}
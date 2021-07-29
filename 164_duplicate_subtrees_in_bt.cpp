// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
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

void printAllDups(Node* root);

int main()
{
	int t;
	struct Node *child;
	scanf("%d\n", &t);
	while (t--)
	{
		map<int, Node*> m;
		int n;
		scanf("%d\n", &n);
		struct Node *root = NULL;
		while (n--)
		{
			Node *parent;
			char lr;
			int n1, n2;
			scanf("%d %d %c", &n1, &n2, &lr);
			if (m.find(n1) == m.end())
			{
				parent = new Node(n1);
				m[n1] = parent;
				if (root == NULL) root = parent;
			}
			else parent = m[n1];
			child = new Node(n2);
			if (lr == 'L')parent->left = child;
			else parent->right = child;
			m[n2]  = child;
		}
		printAllDups(root);
		cout << endl;
	}
	return 0;
}// } Driver Code Ends


//function Template for C++

/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/
// you are required to complete this function
// the function should print all the root node of the
// duplicate subtree in non-decreasing order
// need not print a new line
string soln(Node *root, map<string, vector<Node*>> &mp)
{
	if (!root)
		return "";

	string s;
	s = soln(root->left, mp) + to_string(root->data) + soln(root->right, mp);
	mp[s].push_back(root);

	return s;
}
void printAllDups(Node* root)
{
	if (root == NULL)
		return;

	map<string, vector<Node*>> mp;
	soln(root, mp);

	vector<int> v;

	int flag = 0;

	for (auto i : mp)
	{
		if (i.second.size() > 1)
		{
			flag = 1;
			v.push_back(i.second[0]->data);
		}
	}

	if (flag == 0)
		cout << -1;
	else
	{
		sort(v.begin(), v.end());
		for (auto i : v)
			cout << i << " ";
	}
}
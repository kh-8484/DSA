// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
  int data;
  Node* next;

  Node(int x) {
    data = x;
    next = NULL;
  }

};

Node* mergeKLists(Node* arr[], int K);

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
  cout << endl;
}

// Driver program to test above functions
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int N;
    cin >> N;
    struct Node *arr[N];
    for (int j = 0; j < N; j++)
    {
      int n;
      cin >> n;

      int x;
      cin >> x;
      arr[j] = new Node(x);
      Node *curr = arr[j];
      n--;

      for (int i = 0; i < n; i++)
      {
        cin >> x;
        Node *temp = new Node(x);
        curr->next = temp;
        curr = temp;
      }
    }

    Node *res = mergeKLists(arr, N);
    printList(res);

  }

  return 0;
}
// } Driver Code Ends


/*Linked list Node structure

struct Node
{
  int data;
  Node* next;

  Node(int x){
      data = x;
      next = NULL;
  }

};
*/

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
Node *mergell(Node *a, Node *b) {
  Node *res = NULL;

  if (a == NULL) {
    return b;
  }
  if (b == NULL) {
    return a;
  }

  if (a->data < b->data) {
    res = a;
    res->next = mergell(a->next, b);
  }

  if (a->data >= b->data) {
    res = b;
    res->next = mergell(a, b->next);
  }

  return res;
}

Node *mergeKLists(Node *arr[], int K)
{
  // Your code here
  for (int i = 1; i < K; i++) {
    arr[0] = mergell(arr[0], arr[i]);
  }
  return arr[0];
}


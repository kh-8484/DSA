// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
  int data;
  struct Node* next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

struct Node* buildList(int size)
{
  int val;
  cin >> val;

  Node* head = new Node(val);
  Node* tail = head;

  for (int i = 0; i < size - 1; i++)
  {
    cin >> val;
    tail->next = new Node(val);
    tail = tail->next;
  }

  return head;
}

void printList(Node* n)
{
  while (n)
  {
    cout << n->data << " ";
    n = n->next;
  }
  cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
Node* reverse(Node* head) {
  Node* curr = head;
  Node* prev = NULL;
  Node* nxt;

  while (curr != NULL) {
    nxt = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nxt;
  }
  return prev;
}



class Solution
{
public:
  struct Node* addTwoLists(struct Node* first, struct Node* second)
  {
    // code here

    first = reverse(first);
    second = reverse(second);
    int carry = 0, sum = 0;

    bool flag = true;

    Node* third;
    Node* temp;

    while (first || second) {
      sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
      carry = sum / 10;
      sum = sum % 10;
      if (flag) {
        third = new Node(sum);
        temp = third;
        flag = false;
      }
      else {
        temp->next = new Node(sum);
        temp = temp->next;
      }
      if (first) {
        first = first->next;
      }
      if (second) {
        second = second->next;
      }
    }

    if (carry > 0) {
      temp->next = new Node(carry);
    }
    return reverse(third);
  }
};


// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;

    cin >> n;
    Node* first = buildList(n);

    cin >> m;
    Node* second = buildList(m);
    Solution ob;
    Node* res = ob.addTwoLists(first, second);
    printList(res);
  }
  return 0;
}
// } Driver Code Ends
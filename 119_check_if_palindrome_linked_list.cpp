// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL,  *tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        cout << isPalindrome(head) << endl;
    }
    return 0;
}

// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*You are required to complete this method */
Node* reverse(Node* slow) {
    if (slow == NULL || slow->next == NULL) {
        return slow;
    }

    Node* newNode = reverse(slow->next);
    slow->next->next = slow;
    slow->next = NULL;
    return newNode;
}

bool isPalindrome(Node *head)
{
    //Your code here
    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow = reverse(slow);
    fast = head;

    while (slow != NULL) {
        if (slow->data != fast->data) {
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}


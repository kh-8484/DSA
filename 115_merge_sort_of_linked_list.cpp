// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/* Function to mergesort the linked list
   It should return head of the modified list  */
void split(Node* head, Node** a, Node** b) {
	Node* fast = head->next;
	Node* slow = head;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	*a = head;
	*b = slow->next;
	slow->next = NULL;
}

Node* merge(Node* a, Node* b) {
	if (a == NULL) {
		return b;
	}
	if (b == NULL) {
		return a;
	}

	Node *head = NULL, *tail = NULL;

	if (a->data < b->data) {
		head = tail = a;
		a = a->next;
	}
	else {
		head = tail = b;
		b = b->next;
	}

	while (a != NULL && b != NULL) {
		if (a->data < b->data) {
			tail->next = a;
			tail = a;
			a = a->next;
		}
		else {
			tail->next = b;
			tail = b;
			b = b->next;
		}
	}

	if (a == NULL) {
		tail->next = b;
	}
	else {
		tail->next = a;
	}
	return head;
}

void MergeSort(Node **headRef) {
	Node* head = *headRef;

	if (head == NULL || head->next == NULL) {
		return;
	}

	Node *a, *b;
	split(head, &a, &b);

	MergeSort(&a);
	MergeSort(&b);

	*headRef = merge(a, b);
}

Node* mergeSort(Node* head) {
	// your code here
	MergeSort(&head);
	return head;
}


// { Driver Code Starts.

void printList(Node* node) {
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

void push(struct Node** head_ref, int new_data) {
	Node* new_node = new Node(new_data);

	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int main() {
	long test;
	cin >> test;
	while (test--) {
		struct Node* a = NULL;
		long n, tmp;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			push(&a, tmp);
		}
		a = mergeSort(a);
		printList(a);
	}
	return 0;
}  // } Driver Code Ends
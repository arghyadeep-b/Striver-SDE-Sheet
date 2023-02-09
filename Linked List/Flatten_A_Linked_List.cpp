#include <bits/stdc++.h>
#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

*****************************************************************/
Node *mergeTwoLists(Node *a, Node *b)
{
    Node *temp = new Node(0);
    Node *res = temp;

    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->child = a;
            temp = temp->child;
            a = a->child;
        }
        else
        {
            temp->child = b;
            temp = temp->child;
            b = b->child;
        }
    }
    if (a != NULL)
        temp->child = a;
    else
        temp->child = b;

    return res->child;
}
Node *flattenLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    head->next = flattenLinkedList(head->next);

    head = mergeTwoLists(head, head->next);

    return head;
}
// Time Complexity: O(n), n=total no. of nodes
// Space Complexity: O(1)
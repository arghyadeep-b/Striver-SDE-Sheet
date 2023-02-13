/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// Logic is correct but code is not working
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head = NULL)
        {
            return head;
        }
        Node *itr = head;
        Node *front = head;
        while (itr != NULL)
        {
            front = itr->next;
            Node *copy = new Node(itr->val);
            itr->next = copy;
            copy->next = front;
            itr = front;
        }
        itr = head;
        while (itr != NULL)
        {
            if (itr->random != NULL)
            {
                itr->next->random = itr->random->next;
            }
            itr = itr->next->next;
        }
        itr = head;
        Node *pseudoHead = new Node(0);
        Node *pseudoLast = pseudoHead, *keep;
        while (itr != NULL)
        {
            front = itr->next->next;

            keep = itr->next;
            pseudoLast->next = keep;
            pseudoLast = pseudoLast->next;

            itr->next = front;
            itr = itr->next;
        }
        return pseudoHead->next;
    }
};
// Time Complexity: O(3n) ~= O(n)
// Space Complexity: O(1)
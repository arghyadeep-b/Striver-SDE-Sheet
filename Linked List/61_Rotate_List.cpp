/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        int count = 0;
        ListNode *p = head;
        ListNode *q = head;
        while (p != NULL)
        {
            p = p->next;
            count++;
        }
        int steps = count - (k % count);
        p = head;
        while (steps > 0)
        {
            steps--;
            q = p;
            p = p->next;
        }
        q->next = NULL;
        if (p == NULL)
        {
            return head;
        }
        ListNode *keepHead = p;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = head;
        return keepHead;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)
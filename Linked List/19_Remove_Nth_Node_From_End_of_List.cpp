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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *q = head, *p = head;
        while (n)
        {
            q = q->next;
            n--;
        }
        if (!q)
        {
            return head->next;
        }
        while (q->next)
        {
            q = q->next;
            p = p->next;
        }
        p->next = p->next->next;
        return head;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = NULL;
        ListNode *next = NULL;
        while (head)
        {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reverseList(slow->next);
        ListNode *dummy = head;
        slow = slow->next;
        while (slow != NULL)
        {
            if (dummy->val != slow->val)
            {
                return false;
            }
            slow = slow->next;
            dummy = dummy->next;
        }
        return true;
    }
};
// Time Complexity: O(n/2)+O(n/2)+O(n/2)
// Space Complexity: O(1)
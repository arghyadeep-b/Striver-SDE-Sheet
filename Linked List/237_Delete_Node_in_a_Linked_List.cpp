/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val; // This works as the given node is not the last node
        node->next = node->next->next;
    }
};
// Time Complexity: O(1)
// Space Complexity: O(n)
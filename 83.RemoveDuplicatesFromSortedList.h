/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head)
            return NULL;
        ListNode * p_fast = head->next, * p_slow = head;
        while(p_fast)
        {
            if (p_fast->val == p_slow->val)
            {
                p_slow->next = p_fast->next;
                delete p_fast;
                p_fast = p_slow->next;
            }
            else
            {
                p_slow = p_slow->next;
                p_fast = p_fast->next;
            }
        }
        return head;
    }
};
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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
        	return false;

        ListNode *pFast = head->next;
        ListNode *pSlow = head;
        while(pFast != NULL && pFast->next != NULL)
        {
        	pFast = pFast->next->next;
        	pSlow = pSlow->next;
        	if (pFast == pSlow)
        		return true;
        }

        return false;
    }
};
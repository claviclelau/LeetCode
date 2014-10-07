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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
        	return NULL;

        ListNode *pFast, *pSlow;
        pFast = pSlow = head;
        while(pFast != NULL && pFast->next != NULL)
        {
        	pFast = pFast->next->next;
        	pSlow = pSlow->next;
        	if (pSlow == pFast)
        		break;
        }

        if (pFast == NULL || pFast->next == NULL)
        	return NULL;

        pFast = head;
        while(pFast != pSlow)
        {
        	pFast = pFast->next;
        	pSlow = pSlow->next;
        }
        return pFast;
    }
};
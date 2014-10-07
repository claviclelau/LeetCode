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
    ListNode *sortList(ListNode *head) {
        return sortListRe(head);
    }
    ListNode * sortListRe(ListNode * head) {
    	if (head == NULL || head->next == NULL)
    		return head;

    	ListNode *pFast, *pSlow;
    	pFast = head->next;
    	pSlow = head;
    	while (pFast != NULL && pFast->next != NULL)
    	{
    		pSlow = pSlow->next;
    		pFast = pFast->next->next;
    	}
    	pFast = sortListRe(pSlow->next);
    	pSlow->next = NULL;
    	pSlow = sortListRe(head);
    	return merge(pSlow, pFast);
    }
    ListNode * merge(ListNode * head1, ListNode * head2)
    {
    	ListNode fakeHead(0);
    	ListNode * pTail = &fakeHead;
    	while (head1 != NULL && head2 != NULL)
    	{
    		if (head1->val < head2->val)
    		{
    			pTail->next = head1;
    			head1 = head1->next;
    		}
    		else
    		{
    			pTail->next = head2;
    			head2 = head2->next;
    		}
    		pTail = pTail->next;
    	}

    	pTail->next = head1 == NULL ? head2 : head1;
    	return fakeHead.next;
    }
};
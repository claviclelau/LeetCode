class Solution {
public:
    ListNode *sortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return sortListRe(head);
    }
	ListNode * sortListRe(ListNode * head)
	{
		if (head == NULL || head->next == NULL)
			return head;
        
		ListNode * p_slow = head, * p_fast = head->next;
		while (p_fast != NULL && p_fast->next != NULL)
		{
			p_slow = p_slow->next;
			p_fast = p_fast->next;
            p_fast = p_fast->next;
		}
		p_fast = p_slow->next;
		p_slow->next = NULL;
		p_slow = sortListRe(head);
		p_fast = sortListRe(p_fast);
		return merge(p_slow, p_fast);
	}
	ListNode * merge(ListNode * node1, ListNode * node2)
	{
		ListNode fakeHead(0);
		ListNode * p_head = & fakeHead;
		while (node1 != NULL && node2 != NULL)
		{
			if (node1->val < node2->val)
			{
				p_head -> next = node1;
				node1 = node1->next;
			}
			else
			{
				p_head -> next = node2;
				node2 = node2->next;
			}
			p_head = p_head->next;
		}
		p_head->next = node1 == NULL ? node2 : node1;
		return fakeHead.next;
	}
};
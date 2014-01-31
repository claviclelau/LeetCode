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
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		if (head==NULL)
			return NULL;
        ListNode * p_slow, * p_fast;
		p_slow = p_fast = head;
		while (p_fast)
		{
			p_fast = p_fast->next;
			if (p_fast==NULL)
				return NULL;
			else
				p_fast = p_fast->next;
			p_slow = p_slow->next;
			if (p_slow==p_fast)
				break;
		}
		if (p_fast==NULL)
			return NULL;
		p_fast = head;
		while(p_fast)
		{
			if (p_fast==p_slow)
				return p_fast;
			p_fast = p_fast->next;
			p_slow = p_slow->next;
		}
    }
};
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
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head==NULL)
			return false;
		
		ListNode * p_slow, * p_fast;
		p_fast = p_slow = head;
		while(p_fast!=NULL)
		{
			p_fast = p_fast->next;
			if (p_fast==NULL)
				return false;
			else
				p_fast = p_fast->next;
			p_slow = p_slow->next;
			if (p_slow==p_fast)
				return true;
		}
		return false;
    }
};
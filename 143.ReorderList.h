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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		if (head==NULL)
			return;
        reorderListRe(head, head);
    }
	bool reorderListRe(ListNode *& head, ListNode * node)
	{
		if (node->next!=NULL&&reorderListRe(head, node->next))
			return true;
			
		if (head==node||head->next==node)
		{
			node->next = NULL;
			return true;
		}
		ListNode * next = head->next;
		head->next = node;
		node->next = next;
		head = next;
		return false;
	}
};
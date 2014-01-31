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
	ListNode *insertionSortList(ListNode *head) {
	        // IMPORTANT: Please reset any member data you declared, as
	        // the same Solution instance will be reused for each test case.
	        if (head == NULL)
				return NULL;
		
			ListNode * elem = head -> next;
	        head -> next = NULL;
			while (elem != NULL)
			{
				head = insertOneElement(head, elem, elem);
			}
			return head;
	    }
		ListNode * insertOneElement(ListNode * head, ListNode * elem, ListNode *& next)
		{
			next = elem->next;
			if (elem->val < head->val)
			{
				elem->next = head;
				return elem;
			}
			ListNode * node = head;
			while (node->next != NULL)
			{
				if (elem->val < node->next->val)
				{
					elem->next = node->next;
					node->next = elem;
	                return head;
				}
				node = node->next;
			}
			node -> next = elem;
	        elem->next = NULL;		//This is important.
			return head;
		}
};
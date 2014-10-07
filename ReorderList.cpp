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
    	if (head == NULL)
    		return;
        reorderListRe(head, head);
    }
    bool reorderListRe(ListNode *& head, ListNode * pNode)
    {
    	if (pNode->next != NULL && reorderListRe(head, pNode->next))
    		return true;
    	if (head == pNode || head->next == pNode)
    	{
    		pNode->next = NULL;
    		return true;
    	}
    	else
    	{
    		pNode->next = head->next;
    		head->next = pNode;
    		head = pNode->next;
    		return false;
    	}
    }
};
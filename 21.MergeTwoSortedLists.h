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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode Head(0);
		ListNode * fakeHead = &Head;
		while(l1&&l2)
		{
			if (l1->val<l2->val)
			{
				fakeHead->next = l1;
				l1 = l1->next;
			}
			else
			{
				fakeHead->next = l2;
				l2 = l2->next;
			}
			fakeHead = fakeHead->next;
		}
		if (l1==NULL)
			fakeHead->next = l2;
		else
			fakeHead->next = l1;
		
		return Head.next;
    }
};
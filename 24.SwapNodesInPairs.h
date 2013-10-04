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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode fakeHead(0);
		fakeHead.next = head;
		head = &fakeHead;
		while(head->next&&head->next->next)
		{
			ListNode * temp = head->next->next;
			head->next->next = temp->next;
			temp->next = head->next;
			head->next = temp;
			head = head->next->next;
		}
		return fakeHead.next;
    }
};
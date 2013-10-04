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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (k<=1)
			return head;
		vector<ListNode *> pointer(k+1);
		ListNode fakeHead(0);
		fakeHead.next = head;
		pointer[0] = &fakeHead;
		int i = 0;
		while(pointer[i])
		{
			if (i==k)
			{
				pointer[1]->next = pointer[k]->next;
				for(int j = k; j>1; j--)
					pointer[j]->next = pointer[j-1];
				pointer[0]->next = pointer[k];
				i = 0;
				pointer[0] = pointer[1];
			}
			else
			{
				pointer[i+1] = pointer[i]->next;
				++i;
			}
		}
		return fakeHead.next;
    }
};
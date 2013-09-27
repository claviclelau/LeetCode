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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head==NULL)
            return NULL;
        ListNode * lessTraverse = NULL, * moreTraverse = NULL, * p_traverse = head, * moreHead = NULL;
        head = NULL;
        while(p_traverse!=NULL)
        {
            if (p_traverse->val<x)
            {
                if (lessTraverse==NULL)
                {
                    head = p_traverse;
                    lessTraverse = p_traverse;
                }
                else
                {
                    lessTraverse->next = p_traverse;
    				lessTraverse = lessTraverse->next;
                }
                p_traverse = p_traverse->next;
            }
            else
            {
                if (moreTraverse==NULL)
                {
                    moreHead = p_traverse;
                    moreTraverse = p_traverse;
                }
                else
                {
                    moreTraverse->next = p_traverse;
					moreTraverse = moreTraverse->next;
                }
                p_traverse = p_traverse->next;
            }
        }
        if (head!=NULL)
        {
            lessTraverse->next = moreHead;
			if (moreTraverse)
				moreTraverse->next = NULL;
            return head;
        }
        else
		{
			moreTraverse->next = NULL;
			return moreHead;
		}
    }
};
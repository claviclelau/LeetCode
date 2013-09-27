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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head==NULL)
            return NULL;
        
        ListNode fakeHead(head->val - 1);
        fakeHead.next = head;
        ListNode * p_ahead = head, * p_behind = &fakeHead;
        ListNode * p_temp;
        while(p_ahead!=NULL && p_ahead->next!=NULL)
        {
            if (p_ahead->val!=(p_ahead->next)->val)
            {
                p_ahead = p_ahead->next;
                p_behind = p_behind->next;
            }
            else
            {
                do
                {
                    p_temp = p_ahead->next;
                    p_ahead->next = p_temp->next;
                    delete p_temp;
                }while(p_ahead->next!=NULL&&p_ahead->val==(p_ahead->next)->val);
                p_temp = p_ahead;
                p_behind->next = p_temp->next;
                delete p_ahead;
                p_ahead = p_behind->next;
            }
        }
        return fakeHead.next;
    }
};
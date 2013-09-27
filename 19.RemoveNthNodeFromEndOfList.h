class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head==NULL)
            return NULL;
        if (head->next==NULL&&n==1)
        {
            delete head;
            return NULL;
        }
        
        ListNode newHead(0);
        newHead.next = head;
        ListNode * p_forward = &newHead;
        ListNode * p_backward = &newHead;
        for (int i = 0; i<n; i++)
        {
            p_forward = p_forward->next;
        }
        while(p_forward->next!=NULL)
        {
            p_forward = p_forward->next;
            p_backward = p_backward->next;
        }
        p_forward = p_backward->next;
        p_backward->next = p_forward->next;
        delete p_forward;
        return newHead.next;
    }
};

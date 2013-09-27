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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (m==n)
            return head;
        ListNode * p_ahead, *p_behind, *p_traverse;
        ListNode fakeHead(0);
        fakeHead.next = head;
        p_ahead = p_behind = &fakeHead;
        for (int i = 0; i<=n; i++)
        {
            if (i<m-1)
                p_behind = p_behind->next;
                
            p_ahead = p_ahead->next;
        }
        p_traverse = p_behind->next;
        ListNode * p_temp;
        for (int i = m; i<n; i++)
        {
            p_temp = p_traverse->next;
            p_traverse->next = p_ahead;
            p_ahead = p_traverse;
            p_traverse = p_temp;
        }
        p_behind->next = p_traverse;
        p_traverse->next = p_ahead;
        
        return fakeHead.next;
    }
};
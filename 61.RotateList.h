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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head==NULL)
            return NULL;
        ListNode * p_ahead = head, * p_behind = head;
        int i_length = 0;
        while (p_ahead!=NULL)
        {
            p_ahead = p_ahead->next;
            ++i_length;
        }
        k = k%i_length;
        
        if (k == 0)
            return head;
        i_length = 0;
        p_ahead = head;
        while (i_length<k)
        {
            p_ahead = p_ahead->next;
            i_length++;
        }

        while (p_ahead->next!=NULL)
        {
            p_behind = p_behind->next;
            p_ahead = p_ahead->next;
        }
        
        p_ahead->next = head;
        head = p_behind->next;
        p_behind->next = NULL;
        return head;
    }
};
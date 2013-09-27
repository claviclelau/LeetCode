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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (lists.size()==0)
            return NULL;
        return mergeLists(lists, 0, lists.size()-1);
    }
    ListNode *mergeLists(vector<ListNode *> &lists, int i_start, int i_end)
    {
        if (i_start==i_end)
            return lists[i_start];
        
        if (i_end == i_start + 1)
            return mergeTwoLists(lists[i_start], lists[i_end]);
            
        return mergeTwoLists(mergeLists(lists, i_start, (i_start+i_end)/2), mergeLists(lists, (i_start+i_end)/2+1, i_end));
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (l1==NULL)
            return l2;         
        else if (l2==NULL)
            return l1;
        
        ListNode * head;
        ListNode * mergeTo, * mergeFrom;
        if (l1->val<l2->val)
        {
            head = l1;
            mergeTo = l1;
            mergeFrom = l2;
        }
        else
        {
            head = l2;
            mergeTo = l2;
            mergeFrom = l1;
        }
        ListNode * p_node;
        ListNode * p_next;
        while (mergeTo->next!=NULL&&mergeFrom!=NULL)
        {
            if (mergeFrom->val>=mergeTo->val&&mergeFrom->val<mergeTo->next->val)
            {
                p_next = mergeFrom->next;
                p_node = mergeTo->next;
                mergeTo->next = mergeFrom;
                mergeFrom->next = p_node;
                mergeFrom = p_next;
            }
            mergeTo = mergeTo->next;
        }
        if (mergeTo->next==NULL)
            mergeTo->next = mergeFrom;
            
        return head;
    }

};
class Solution {
public:
    ListNode * copyList(ListNode * p_list)
    {
        if (p_list==NULL)
            return NULL;
            
        ListNode * answer = new ListNode(p_list->val);
        p_list = p_list->next;
        ListNode * traverse = answer;
        while(p_list!=NULL)
        {
            traverse->next = new ListNode(p_list->val);
            traverse = traverse->next;
            p_list = p_list->next;
        }
        return answer;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (l1==NULL&&l2==NULL)
            return NULL;
        else if (l1==NULL)
            return copyList(l2);
        else if (l2==NULL)
            return copyList(l1);
        
        ListNode* answer;
        ListNode* traverse;
        int i_carry = 0;
        int sum = i_carry + l1->val + l2->val;
        answer = new ListNode(sum%10);
        traverse = answer;
        i_carry = sum/10;
        l1 = l1->next;
        l2 = l2->next;
        while(l1!=NULL&&l2!=NULL)
        {
            sum = i_carry + l1->val + l2->val;
            traverse->next = new ListNode(sum%10);
            i_carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
            traverse = traverse->next;
        }
        if (l1==NULL&&l2==NULL)
        {
            if (i_carry != 0)
                traverse->next = new ListNode(i_carry);
                
            return answer;       
        }
        else if (l1==NULL)
        {
            while (i_carry!=0&&l2!=NULL)
            {
                sum = i_carry + l2->val;
                traverse->next = new ListNode(sum%10);
                i_carry = sum/10;
                l2 = l2->next;
                traverse = traverse->next;
            }
            if (l2==NULL&&i_carry!=0)
            {
                traverse->next = new ListNode(i_carry);

            }
            else if (i_carry==0)
            {
                traverse->next = copyList(l2);
                
            }
            return answer;
        }
        else if (l2==NULL)
        {
            while (i_carry!=0&&l1!=NULL)
            {
                sum = i_carry + l1->val;
                traverse->next = new ListNode(sum%10);
                i_carry = sum/10;
                l1 = l1->next;
                traverse = traverse->next;
            }
            if (l1==NULL&&i_carry!=0)
            {
                traverse->next = new ListNode(i_carry);

            }
            else if (i_carry==0)
            {
                traverse->next = copyList(l1);
                
            }
            return answer;
        }
        
    }
};
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
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode * pRet = head;
        head = head->next;
        pRet->next = NULL;
        while (head != NULL)
        {
            ListNode * tempNode;
            if (head->val <= pRet->val)
            {
                tempNode = head->next;
                head->next = pRet;
                pRet = head;
                head = tempNode;
                continue;
            }
            tempNode = pRet;
            while (tempNode->next != NULL)
            {
                if (tempNode->next->val >= head->val)
                {
                    ListNode * tempNode2 = head->next;
                    head->next = tempNode->next;
                    tempNode->next = head;
                    head = tempNode2;
                    break;
                }
                tempNode = tempNode->next;
            }
            if (tempNode->next == NULL)
            {
                tempNode->next = head;
                tempNode = head;
                head = head->next;
                tempNode->next = NULL;
            }
        }
        return pRet;
    }
};
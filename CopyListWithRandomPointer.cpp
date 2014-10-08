/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if (head == NULL)
    		return NULL;
        RandomListNode * pTraverse;
        pTraverse = head;
        while (pTraverse != NULL)
        {
        	RandomListNode * tempNode = new RandomListNode(pTraverse->label);
        	tempNode->next = pTraverse->next;
        	pTraverse->next = tempNode;
        	pTraverse = tempNode->next;
        }

        pTraverse = head;
        RandomListNode fake_head(-1);
        RandomListNode * copyList = &fake_head;
        while(pTraverse)
        {
        	if (pTraverse->random == NULL)
        		pTraverse->next->random = NULL;
        	else
        		pTraverse->next->random = pTraverse->random->next;
        	pTraverse = pTraverse->next->next;
        }
        pTraverse = head;
        while(pTraverse)
        {
        	copyList->next = pTraverse->next;
        	copyList = copyList->next;
        	pTraverse->next = copyList->next;
        	pTraverse = pTraverse->next;
        }
        return fake_head.next;
    }
};
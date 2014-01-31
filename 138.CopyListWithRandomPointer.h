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
        RandomListNode * p_traverse = head;
		while (p_traverse)
		{
			RandomListNode * temp_node = new RandomListNode (p_traverse->label);
			temp_node->next = p_traverse->next;
			p_traverse->next = temp_node;
			p_traverse = temp_node->next;
		}
		p_traverse = head;
		RandomListNode fake_head(0);
		RandomListNode * copy_list = &fake_head;
		while (p_traverse)
		{
		    if (p_traverse->random == NULL)
		        p_traverse->next->random = NULL;
		    else
			    p_traverse->next->random = p_traverse->random->next;
            p_traverse = p_traverse->next->next;
        }
        p_traverse = head;
        while (p_traverse)
        {
			copy_list->next = p_traverse->next;
			p_traverse->next = p_traverse->next->next;
			p_traverse = p_traverse->next;
			copy_list = copy_list->next;
		}
		return fake_head.next;
    }
};

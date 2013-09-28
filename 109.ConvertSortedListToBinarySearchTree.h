/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return sortedListToBSTRe(head, GetLength(head));
    }
	int GetLength(ListNode * head)
	{
		int i_length = 0;
		while(head)
		{
			++i_length;
			head = head->next;
		}
		return i_length;
	}
    TreeNode * sortedListToBSTRe(ListNode * head, int i_length)
	{
		if (head==NULL||i_length==0)
			return NULL;
		if (i_length==1)
			return new TreeNode(head->val);
		int temp_length = (i_length+1)/2;
		ListNode * traverse = head;
		while(--temp_length)
			traverse = traverse->next;
		TreeNode * answer = new TreeNode(traverse->val);
		answer->left = sortedListToBSTRe(head, (i_length+1)/2-1);
		answer->right = sortedListToBSTRe(traverse->next, i_length/2);
		return answer;
	}
};
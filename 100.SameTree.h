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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return isSameTreeRe(p, q);
    }
	bool isSameTreeRe(TreeNode *p, TreeNode *q)
	{
		if (p==NULL&&q==NULL)
			return true;
		
		if ((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL))
			return false;
		
		if (p->val!=q->val)
			return false;
		
		if (isSameTreeRe(p->left, q->left)&&isSameTreeRe(p->right, q->right))
			return true;
		
		return false;
	}
};
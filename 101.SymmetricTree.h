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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return isSymmetricNonRe(root);
    }
	bool isSymmetricRe(TreeNode * left_root, TreeNode * right_root)
	{
		if (left_root==NULL&&right_root==NULL)
			return true;
		if ((left_root==NULL&&right_root!=NULL)||(left_root!=NULL&&right_root==NULL))
			return false;
		if (left_root->val!=right_root->val)
			return false;
		if (isSymmetricRe(left_root->right, right_root->left)&&isSymmetricRe(left_root->left, right_root->right))
			return true;
		
		return false;
	}
	bool isSymmetricNonRe(TreeNode * root)
	{
		if (!root)
			return true;
		queue <TreeNode *> my_queue;
		my_queue.push(root->left);
		my_queue.push(root->right);
		while(!my_queue.empty())
		{
			TreeNode * node_1 = my_queue.front();
			my_queue.pop();
			TreeNode * node_2 = my_queue.front();
			my_queue.pop();
			if (!node_1&&!node_2) continue;
			if (!node_1||!node_2||node_1->val!=node_2->val)
				return false;
			my_queue.push(node_1->left);
			my_queue.push(node_2->right);
			my_queue.push(node_1->right);
			my_queue.push(node_2->left);
		}
		return true;
	}
};
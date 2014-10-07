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
    vector<int> preorderTraversal(TreeNode *root) {
        return preorderTraversalNonRe(root);
    }
    vector <int> preorderTraversalRe(TreeNode * root)
    {
    	vector <int> vRet;
    	preorderTraversalRe_1(root, vRet);
    	return vRet;
    }
    void preorderTraversalRe_1(TreeNode * root, vector<int> & vRet)
    {
    	if (root==NULL)
    		return;

    	vRet.push_back(root->val);
    	preorderTraversalRe_1(root->left, vRet);
    	preorderTraversalRe_1(root->right, vRet);
    }

    vector <int> preorderTraversalNonRe(TreeNode * root)
    {
    	vector <int> vRet;
    	if (root == NULL)
    		return vRet;

    	stack<TreeNode *> stk;
    	TreeNode * node = root;
    	TreeNode * last_pop = NULL;
    	while (node != NULL || !stk.empty())
    	{
    		while (node != NULL)
    		{
    			stk.push(node);
    			vRet.push_back(node->val);
    			node = node->left;
    		}
    		node = stk.top();
    		if (node->right == NULL || last_pop == node->right)
    		{
    			last_pop = stk.top();
    			stk.pop();
    			node = NULL;
    		}
    		else
    		{
    			node = node->right;
    		}
    	}
    	return vRet;
    }
};
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
    vector<int> postorderTraversal(TreeNode *root) {
        return postorderTraversalNonRe(root);
    }
    vector <int> postorderTraversalRe(TreeNode * root) {
        vector <int> vRet;
        postorderTraversalRe_1(root, vRet);
        return vRet;
    }
    void postorderTraversalRe_1(TreeNode * root, vector<int> & vRet)
    {
        if (root == NULL)
            return;

        postorderTraversalRe_1(root->left, vRet);
        postorderTraversalRe_1(root->right, vRet);
        vRet.push_back(root->val);
    }
    vector<int> postorderTraversalNonRe(TreeNode * root)
    {
        vector <int> vRet;
        stack <TreeNode *> stk;
        TreeNode * node = root;
        TreeNode * last_pop = NULL;
        while (node != NULL || !stk.empty())
        {
            while (node != NULL)
            {
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            if (node->right == NULL || last_pop == node->right)
            {
                vRet.push_back(node->val);
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
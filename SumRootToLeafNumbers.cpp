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
    int sumNumbers(TreeNode *root) {
        int ret = 0;
        if (root != NULL)
        {
            DFSRe(root, ret);
        }
        return ret;
    }
    
    void DFSRe(TreeNode * root, int & sum)
    {
        if (root->left == NULL && root->right == NULL)
        {
            sum *= 10;
            sum += root->val;
            return;
        }
        int left_sum = 0;
        int right_sum = 0;
        if (root->left)
        {
            left_sum = sum * 10 + root->val;
            DFSRe(root->left, left_sum);
        }
        
        if (root->right)
        {
            right_sum = sum * 10 + root->val;
            DFSRe(root->right, right_sum);
        }
        sum = left_sum + right_sum;
    }
};
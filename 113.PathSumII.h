class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > v_result;
        vector<int> v_current;
        DFS(root, sum, v_current, v_result);
        return v_result;
    }
    void DFS(TreeNode * root, int sum, vector<int> & v_current, vector<vector<int>> & v_result)
    {
        if (root==NULL)
            return;
        if (root->left==NULL&&root->right==NULL)
        {
            if (root->val==sum)
            {
                v_current.push_back(sum);
                v_result.push_back(v_current);
                v_current.pop_back();
            }
            return;
        }
        
        v_current.push_back(root->val);
        
        if (root->left!=NULL)
        {
            DFS(root->left, sum-root->val, v_current, v_result);
        }
        
        if (root->right!=NULL)
        {
            DFS(root->right, sum-root->val, v_current, v_result);
        }
        v_current.pop_back();
    }
};
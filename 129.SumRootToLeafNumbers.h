class Solution {
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int answer = 0;
        DFS(root, 0, answer);
        return answer;
    }
    void DFS(TreeNode * root, int i_current, int & answer)
    {
        if (root==NULL)
            return;
        if (root->left==NULL&&root->right==NULL)
        {
            answer+=i_current*10+root->val;
            return;
        }
        if (root->left!=NULL)
            DFS(root->left, i_current*10+root->val, answer);
            
        if (root->right!=NULL)
            DFS(root->right, i_current*10+root->val, answer);
    }
};
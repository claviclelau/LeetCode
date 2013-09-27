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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > answer;
        if (!root)
            return answer;
        list <TreeNode *> level_list[2];
        vector<int> v_level;
        list <TreeNode *>::iterator iter;
        int i_current = 0, i_next = 1;
        bool b_forward = true;
        level_list[0].push_back(root);
        while(!level_list[i_current].empty())
        {
            v_level.clear();
            if (b_forward)
            {
                while(!level_list[i_current].empty())
                {
                    TreeNode * node = level_list[i_current].front();
                    if (node->left)
                        level_list[i_next].push_back(node->left);
                    if (node->right)
                        level_list[i_next].push_back(node->right);
                    v_level.push_back(node->val);
                    level_list[i_current].pop_front();
                }
                answer.push_back(v_level);
                i_current = i_next;
                i_next ^= 1;
                b_forward = !b_forward;
            }
            else
            {
                while(!level_list[i_current].empty())
                {
                    TreeNode * node = level_list[i_current].back();
                    if (node->right)
                        level_list[i_next].push_front(node->right);
                    if (node->left)
                        level_list[i_next].push_front(node->left);
                    v_level.push_back(node->val);
                    level_list[i_current].pop_back();
                }
                answer.push_back(v_level);
                i_current = i_next;
                i_next ^=1;
                b_forward = !b_forward;
            }
        }
        return answer;
    }
};
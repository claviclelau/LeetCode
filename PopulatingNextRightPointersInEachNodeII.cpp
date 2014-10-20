/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        
        TreeLinkNode * head = root;
        while (head != NULL)
        {
            TreeLinkNode * node = head;
            head = NULL;
            TreeLinkNode * previous = NULL;
            while (node != NULL)
            {
                if (head == NULL)
                {
                    if (node->left != NULL)
                    {
                        head = node->left;
                    }
                    else
                        head = node->right;
                }
                if (node->right != NULL)
                {
                    if (previous != NULL)
                    {
                        previous->next = node->left == NULL ? node->right : node->left;
                    }
                    if (node->left != NULL)
                        node->left->next = node->right;
                    previous = node->right;
                }
                else if (node->left != NULL)
                {
                    if (previous != NULL) {
                        previous->next = node->left;
                    }
                    previous = node->left;
                }
                node = node->next;
            }
            if (previous)
                previous->next = NULL;
        }
    }
};
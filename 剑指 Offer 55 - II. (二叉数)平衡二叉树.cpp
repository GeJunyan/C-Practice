/*输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int getDepth(TreeNode* root, int depth, bool &res)
    {
        if(root == NULL) return depth;
        depth ++;
        int tmp1 = getDepth(root->left, depth, res);
        int tmp2 = getDepth(root->right, depth, res);
        if(abs(tmp1-tmp2) > 1) 
            res = false;
        return max(tmp1, tmp2);
    }

    bool isBalanced(TreeNode* root) {
        bool res = true;
        getDepth(root, 0, res);
        return res;
    }
};

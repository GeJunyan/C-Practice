//输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
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

    TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd,
                        vector<int>&preorder, int preorderBegin, int preorderEnd)
    {
        if(preorderBegin == preorderEnd) return NULL;
        int rootvalue = preorder[preorderBegin];
        TreeNode * root = new TreeNode(rootvalue);
        
        //找中序遍历中 根的编号
        int index = -1;
        for(int i = 0; i < inorder.size(); i++)
        {
            if(inorder[i] == rootvalue)
            {
                index = i;
                break;
            }
        }

        //切割中序(左闭右开)
        int LeftInorderBegin = inorderBegin;
        int LeftInorderEnd = index;
        /***************************/
        int RightInorderBegin = index + 1;
        int RightInorderEnd = inorderEnd;

        //切割前序(左闭右开)
        int LeftPreorderBegin = preorderBegin + 1;
        int LeftPreorderEnd = preorderBegin + 1 + index - inorderBegin;
        /***************************/
        int RightPreorderBegin = preorderBegin + 1 + index - inorderBegin;
        int RightPreorderEnd = preorderEnd;

        root->left = traversal(inorder, LeftInorderBegin, LeftInorderEnd,
                               preorder, LeftPreorderBegin, LeftPreorderEnd);
        root->right = traversal(inorder, RightInorderBegin, RightInorderEnd,
                                preorder, RightPreorderBegin, RightPreorderEnd);
        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if (inorder.size() == 0 || preorder.size() == 0) return NULL;
        return traversal(inorder, 0, inorder.size(), preorder, 0, preorder.size());
    }
};

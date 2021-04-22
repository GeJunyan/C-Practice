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

/*
整体的遍历过程

    我们从根节点开始遍历；

    如果当前节点的值大于 ppp 和 qqq 的值，说明 ppp 和 qqq 应该在当前节点的左子树，因此将当前节点移动到它的左子节点；

    如果当前节点的值小于 ppp 和 qqq 的值，说明 ppp 和 qqq 应该在当前节点的右子树，因此将当前节点移动到它的右子节点；

    如果当前节点的值不满足上述两条要求，那么说明当前节点就是「分岔点」。此时，ppp 和 qqq 要么在当前节点的不同的子树中，要么其中一个就是当前节点。
。*/

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        while (true) {
            if (p->val < ancestor->val && q->val < ancestor->val) {
                ancestor = ancestor->left;
            }
            else if (p->val > ancestor->val && q->val > ancestor->val) {
                ancestor = ancestor->right;
            }
            else {
                break;
            }
        }
        return ancestor;

    }
};

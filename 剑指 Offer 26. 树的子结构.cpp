/*输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。*/
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


    bool check(TreeNode* A, TreeNode* B)
    {
        if(A == nullptr && B == nullptr)
            return true;
        
        else if(A == nullptr && B != nullptr)
            return false;

        else if(A != nullptr && B == nullptr)
            return true;
        
        else if(A->val != B->val)
            return false;

        else
            return check(A->left, B->left) && check(A->right, B->right);

    }


    bool isSubStructure(TreeNode* A, TreeNode* B) {

        if(B == nullptr)
            return false;

        if(check(A,B))
            return true;

        bool l = false, r = false;
        if(A->left)
            l = isSubStructure(A->left, B);
        if(A->right)
            r = isSubStructure(A->right, B);
        return l || r;

    }
};

/*一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



class Solution {

private:
    // 维护当前的路径
    vector<int> path;
    // 结果 
    vector<vector<int>> res;


public:

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return res;
    }


    void dfs(TreeNode *curr, int target)
    {
        if(curr != nullptr)
        {
            target = target - curr->val;
            path.push_back(curr->val);
            

            if(target != 0 || curr->left != nullptr || curr->right != nullptr)//不满足条件
            {
                dfs(curr->left, target);
                dfs(curr->right, target);
            }
            
            else//满足条件
            {
                res.push_back(path);
            }

            //回溯
            path.pop_back();//pop_back 是 删除vector中的元素
        }

    }
};

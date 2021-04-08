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
    vector<int> levelOrder(TreeNode* root) {

        //层序遍历 使用队列
        queue<TreeNode*> my_queue;
        vector<int> res;
        if (root == nullptr) return res;
        
        //把根节点放入队列
        my_queue.push(root);
        while(!my_queue.empty())
        {
            TreeNode* node = my_queue.front();//记录首位的
            my_queue.pop();//弹出首位并写出来
            res.push_back(node->val);

            if(node->left) my_queue.push(node->left);//把下一层放进去
            if(node->right) my_queue.push(node->right);
        }
        return res;
    }
};

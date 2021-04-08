/*从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。*/
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
    vector<vector<int>> levelOrder(TreeNode* root) {

        //层序遍历的变体
        queue<TreeNode *> my_queue;
        vector<vector<int>> res;

        if(!root) return res;
        my_queue.push(root);
        while(!my_queue.empty())
        {
            int cnt = my_queue.size();//////////一定要写出来 不能写在循环条件里
            vector<int> temp;
            //每次遍历那一层的
            for(int i = 0; i < cnt; i++)
            {
                TreeNode* node = my_queue.front();
                my_queue.pop();
                temp.push_back(node->val);
                if(node->left) my_queue.push(node->left);
                if(node->right) my_queue.push(node->right);
            }
            res.push_back(temp);
        }        
        return res;

    }
};

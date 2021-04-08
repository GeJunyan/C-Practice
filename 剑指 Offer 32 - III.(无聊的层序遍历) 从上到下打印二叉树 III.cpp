/*请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。*/
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


        queue<TreeNode*> my_queue;
        vector<vector<int>> res;

        if(!root) return res;
        my_queue.push(root);
        bool flag = 0;
        while(!my_queue.empty())
        {
            int cnt = my_queue.size();
            vector<int> temp;

            for(int i = 0; i < cnt; i++)
            {
                TreeNode* node = my_queue.front();
                my_queue.pop();
                temp.push_back(node->val);
                if(node->left) my_queue.push(node->left);
                if(node->right) my_queue.push(node->right);
            }
            if(flag) reverse(temp.begin(),temp.end()); 

            flag = !flag;
            res.push_back(temp);
        }

        return res;

    }
};

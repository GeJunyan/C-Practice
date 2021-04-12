/*输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。*/
class Solution {

/*递归求解

    按照后续遍历的实现最后一个元素是根节点， 比根节点的小的说明是在左子树，比根节点大的说明在右子树

    思路

    递归按照数组的开始位置 start 和结束位置 end
    递归结束 start>= end 表示只有一个结点，必然没问题，直接返回true
    分别按照大小比较去找到左子树的结束位置和右子树的结束位置
    判断右子树的结束位置是否正好是根节点，否则就是异常
    正常情况下，继续去拆分成左右子树去递归调用
*/
private:
    bool dfs(vector<int> &postorder, int start, int end)
    {
        if(start >= end) return true;
        int p = start;
        int rootval = postorder[end];
        
        // 找左子树的结束位置
        while(postorder[p] < rootval)
        {
            p++;
        }

        int leftEnd = p - 1; //记录左子树结束的位置

        // 找右子树的结束位置
        while (postorder[p] > rootval)
        {
            p++;
        }

        return (p == end) && dfs(postorder, start, leftEnd) && dfs(postorder, leftEnd+1, end-1);

    }

public:
    bool verifyPostorder(vector<int>& postorder) {
        return dfs(postorder, 0, postorder.size() - 1);

    }
};

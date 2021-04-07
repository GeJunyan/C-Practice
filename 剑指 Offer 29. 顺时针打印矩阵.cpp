/*输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。*/
class Solution {
public:
/*
按层模拟的方法：
对于每层，从左上方开始以顺时针的顺序遍历所有元素。假设当前层的左上角位于 (top,left)右下角位于 (bottom,right)，
按照如下顺序遍历当前层的元素。

    从左到右遍历上侧元素，依次为 (top,left)(\textit{top}, \textit{left})(top,left) 到 (top,right)(\textit{top}, \textit{right})(top,right)。

    从上到下遍历右侧元素，依次为 (top+1,right) 到 (bottom,right)。

    如果 left<right 且 top<bottom，则从右到左遍历下侧元素，依次为 (bottom,right−1) 到 (bottom,left+1)
    ，以及从下到上遍历左侧元素，依次为 (bottom,left)到 (top+1,left)。

遍历完当前层的元素之后，将 left 和 top 分别增加 1，将 right 和 bottom 分别减少 1，进入下一层继续遍历，直到遍历完所有元素为止。



*/
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        if(matrix.size() == 0 || matrix[0].size() == 0)
        {
            return {};
        }

        //二维数组行数和列数的写法 重要
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> res;
        
        //初始化位置
        int left = 0;
        int top = 0;
        int right = cols - 1;
        int bottom = rows - 1;

        while(left <= right && top <= bottom)
        {
            //从左往右
            for(int col = left; col <= right; col++)
            {
                res.push_back(matrix[top][col]);
            }
            //从上往下 row = top + 1 
            for(int row = top + 1; row <= bottom; row++)
            {
                res.push_back(matrix[row][right]);
            }

            if (left < right && top < bottom) {//这个判断必须要加 否则可能重复输出
                 //从右往左
            for (int col = right - 1; col > left; col--) 
            {
                res.push_back(matrix[bottom][col]);
            }

            //从下往上
            for (int row = bottom; row > top; row--) 
            {
                res.push_back(matrix[row][left]);
            }
            }

           

            left++;
            right--;
            top++;
            bottom--;

        }
        return res;

    }
};

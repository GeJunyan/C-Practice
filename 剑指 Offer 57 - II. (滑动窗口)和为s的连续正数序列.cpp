/*输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。*/

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
         
        vector<vector<int>> res;

        //滑动窗口
        int left = 1;
        int right = 1;

        int sum = 0;
        while(left <= target / 2)
        {
            if(sum < target)
            {
                sum = sum + right;
                right++;
            }

            else if(sum > target)
            {
                sum = sum - left;
                left++;
            }

            else
            {   
                vector<int> temp;
                for(int j = left; j < right; j++)
                {
                    temp.push_back(j);
                }
                res.push_back(temp);
                sum = sum - left;
                left ++;
            }

        }
        return res;

    }
};

/*输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。*/

class Solution {
public:

    //动态规划问题
    /*
    只要看dp[i-1]对当前产生什么贡献，负贡献就不加，正贡献就加上
    dp[i]之和dp[i-1]和num[i]有关系 所以可以直接用num代替dp，直接在num上修改（但是为了清楚，不直接修改，还是定义一个dp）
    */

    int maxSubArray(vector<int>& nums) {
        //定义dp
        vector<int> dp(nums.size(), 0);
        //初始化dp
        dp[0] = nums[0];
        //定义一个变量维护最大值
        int res = dp[0];
        for(int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-1], 0) + nums[i]; //这个写法要注意！！！！！！！！！！！！！
            res = max(res, dp[i]);
        }
        return res;

    }
};

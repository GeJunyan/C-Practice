/*一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。*/
class Solution {
public:
    int numWays(int n) {

        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        int pre = 1;
        int cur = 2;
        int sum = -1;

        while(n > 2)
        {
            /*依然是动态规划，不断更新pre 和 cur*/
            sum = (pre + cur)%1000000007;
            pre = cur;
            cur = sum;
            n--;
        }
        return sum;
    }
};

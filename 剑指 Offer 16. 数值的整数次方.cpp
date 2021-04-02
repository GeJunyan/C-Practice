/*实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数*/
class Solution {
public:
    double myPow(double x, int n) {
        
        long m = n; // 为了过编译加上的 没有什么意义
        if(n < 0)
        {
            x = 1/x;
            m = -m;
        }

        double ans = 1.0;
        while(m > 0)
        {
            if ((m & 1) == 1)
            {
                ans = ans * x;
            }
            x = x * x;
            m = m >> 1;
        }

        return ans;

    }
};

/*写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
*/
class Solution {
public:
    int fib(int n) {

        /*动态规划!!!!!!!!!!!!!!!!!!!!*/
        //初始条件
        int a = 0;
        int b = 1;

        int sum = -1;

        while(n >= 1)
        {
            sum = (a + b) % 1000000007;

            //下移
            a = b; 
            b = sum;
            
            n--;
        }
        return a;
        
    }
};

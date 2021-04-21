/*把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。*/

class Solution {
public:

/*https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/solution/nge-tou-zi-de-dian-shu-dong-tai-gui-hua-ji-qi-yo-3/*/
    vector<double> dicesProbability(int n) {

       int dp[15][70];
       memset(dp, 0, sizeof(dp));

       //初始化
       for(int i = 1; i <= 6; i++)
       {
           dp[1][i] = 1;
       }

       for(int i = 2; i <= n; i++)
       {
           for(int j = i; j <= 6*i; j++)
           {
               for(int cur = 1; cur <= 6; cur++)
               {
                   if (j - cur <= 0) break;
                   dp[i][j] += dp[i-1][j-cur];

               }
           }
       }
       int all = pow(6, n);
       vector<double> ret;
       for (int i = n; i <= 6 * n; i ++) {
           ret.push_back(dp[n][i] * 1.0 / all);
        }
       return ret;


    }
};

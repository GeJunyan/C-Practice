/*在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
*/

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        //动态规划问题 初始化一个dp数组 记录最大值

        int m = grid.size();
        int n = grid[0].size();

        //注意这个初始化的写法！！！！
        vector<vector<int>>dp(grid.size(), vector<int>(n, 0));
        
        //把第一行和第一列都初始化一下
        dp[0][0] = grid[0][0];
        
        for(int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        
        for(int i = 1; i < n; i++)
            dp[0][i] = dp[0][i - 1] + grid[0][i];

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
        
    }
};

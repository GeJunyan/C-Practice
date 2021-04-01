/*地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
请问该机器人能够到达多少个格子？*/
class Solution {
public:

    int result = 0;
    int dfs(vector<vector<bool>> &vis, int m, int n, int i, int j, int k)
    {
        //dfs
       
        //1. 越界情况 或 不符合要求的情况
        if(i < 0 || i >= m || j < 0 || j >= n || (i%10+i/10+j%10+j/10) > k) 
            return 0;
        
        //2. 符合要求
        if(!vis[i][j])
        {
            vis[i][j] = true;
            result ++;
            dfs(vis, m, n, i + 1, j, k);
            dfs(vis, m, n, i, j + 1, k);
        }
        return result;
    }

    int movingCount(int m, int n, int k) {
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        return dfs(vis, m, n, 0, 0, k);
    }
};

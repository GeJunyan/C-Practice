/*请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]
但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。*/

class Solution {
public:


    bool dfs(vector<vector<char>>& board,string word, int i, int j, int k)
    {
        int rows = board.size();
        int cols = board[0].size();

        //1.越界情况 字符不对的情况直接返回flase
        if(i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k])
            return false;
        //2.字符对的情况 且已经匹配完了 直接返回true
        if (k == word.size() - 1) return true;

        board[i][j] = '\0';
        //3. dfs
        bool res = dfs(board, word, i+1,j,k+1)||dfs(board, word, i-1,j,k+1)||dfs(board, word, i,j+1,k+1)||dfs(board, word, i,j-1,k+1);
        //4. 回溯
        board[i][j] = word[k];

        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(dfs(board,word,i,j,0)) return true;
            }
        }

        return false;
        /*
        本问题是典型的矩阵搜索问题，可使用 深度优先搜索（DFS）+ 剪枝解决。

    深度优先搜索： 可以理解为暴力法遍历矩阵中所有字符串可能性。DFS 通过递归，先朝一个方向搜到底，再回溯至上个节点，沿另一个方向搜索，以                   此类推。
    剪枝： 在搜索中，遇到这条路不可能和目标字符串匹配成功 的情况（例如：此矩阵元素和目标字符不同、此元素已被访问），则应立即返回，称之为            可行性剪枝 。

     DFS 解析：

    递归参数： 当前元素在矩阵 board 中的行列索引 i 和 j ，当前目标字符在 word 中的索引 k 。
    终止条件：
        返回 false： (1) 行或列索引越界 或 (2) 当前矩阵元素与目标字符不同 或 (3) 当前矩阵元素已访问过 （ (3) 可合并至 (2) ） 。
        返回 true ： k = len(word) - 1 ，即字符串 word 已全部匹配。
        */
    }
};

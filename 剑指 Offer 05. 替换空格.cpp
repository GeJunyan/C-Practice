/*请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."
*/

class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                ans += "%20";
            }
            else ans += s[i];
        }
        return ans;
    }
};

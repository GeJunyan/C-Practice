/*给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。*/

class Solution {
public:
    int translateNum(int num) {

        //动态规划问题

        string s = to_string(num);

        int p = 0, q = 0, r = 1;

        for(int i = 0; i < s.size(); i++)
        {
            //移位
            p = q;
            q = r;
            r = 0;
            r = r + q;
            if(i == 0) continue;

            auto temp = s.substr(i - 1, 2);
            if(temp <= "25" && temp >= "10")
            {
                r = r + p;
            }
        }
        return r;
    }
};

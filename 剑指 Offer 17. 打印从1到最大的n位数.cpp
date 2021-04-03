/*输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。*/
class Solution {
public:
    vector<int> printNumbers(int n) {
        
        vector<int> res;
        if (n == 0) res.push_back(0);
    
        int num = pow(10, n);
        for(int i = 1; i < num; i++)
        {
            res.push_back(i);
        }
        return res;
    

    }
};

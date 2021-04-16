/*输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。*/

class Solution {
public:
/*找规律：
我们假设高位为high，当前位为cur，低位为low，i代表着需要统计的位置数（1对应个位，10对应十位，100对应百位），则对每一位的个数count有：
cur=0,count = high*i;
cur=1,count=high*i+low+1;
cur>1,count=high*i+i
最终累加所有位置上的个数即最终答案。*/
    int countDigitOne(int n) {
        
        int res = 0;
        long i = 1;
        while(n/i != 0)
        {
            long high = n / (i*10); //当前位之前的数字存在high里
            long cur = (n / i) % 10; //获得当前位的数字
            long low = n - (n / i) * i;

            if(cur == 0) res += high * i;
            else if(cur == 1) res += high * i + low + 1;
            else res += high * i + i;

            i = i * 10;
        }
        return res;
    }
};

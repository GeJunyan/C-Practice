/*假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int maxprofit = 0;
        int minprice = prices[0];
        for(int i = 0; i　< prices.size(); i++)
        {
            //1. 今天收益最大　就更新最大收益
            if(prices[i] > minprice)
            {
                maxprofit = max(maxprofit, prices[i] - minprice);
            }

            //2.　否则更新最小值
            else
            {
                minprice = min(minprice, prices[i]);
            }
        }
        return maxprofit;


    }
};

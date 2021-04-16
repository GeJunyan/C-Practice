/*输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。*/

//尤其要注意的是sort的写法

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string ans;
        for (int i = 0; i < nums.size(); i++)
            strs.push_back(to_string(nums[i]));
      
        sort(strs.begin(), strs.end(), [](string& s1, string& s2){return s1 + s2 < s2 + s1;});//////////最要学习这句////////////////
      
      for (int i = 0; i < strs.size(); i++)
            ans += strs[i];

        return ans;

    }
};

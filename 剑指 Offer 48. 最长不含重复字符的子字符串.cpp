/*请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int max_sub = 0;
        int map[128] = {0};//map统计字符在当前子串出现次数,字符的ascii码值小于128
        int start = 0;

        for(int i = 0; i < s.size(); i++)
        {
            map[s[i]]++;
            while(map[s[i]] == 2)
                map[s[start++]]--;
            max_sub = max(max_sub, i - start + 1);
        }
        return max_sub;
    }
};

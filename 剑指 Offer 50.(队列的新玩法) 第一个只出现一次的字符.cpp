/*在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。*/
class Solution {
public:
    char firstUniqChar(string s) {
        
        
        unordered_map<char, int> position;
      
      //注意这个写法！！！！！！！！！！！！！！
        queue<pair<char, int>> q;
      
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (!position.count(s[i])) {
                position[s[i]] = i;
                q.emplace(s[i], i);
            }
            else {
                position[s[i]] = -1;
                while (!q.empty() && position[q.front().first] == -1) {
                    q.pop();
                }
            }
        }
        return q.empty() ? ' ' : q.front().first;

    }
};

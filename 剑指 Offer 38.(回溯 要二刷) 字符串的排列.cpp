/*输入一个字符串，打印出该字符串中字符的所有排列。*/

class Solution {
public:

    //防止重复
    set<string> store;
    vector<string> res;

    void dfs(string& s, string &cur, vector<bool> used)
    {
        if(cur.size() == s.size())
        {
            store.insert(cur);
            return;
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(used[i]) continue;
            cur = cur + s[i];
            used[i] = true;
            dfs(s, cur, used);
            used[i] = false;
            cur.pop_back();
        }
    }

    vector<string> permutation(string s) {
        string cur = "";
        vector<bool> used(s.size(), false);
        dfs(s, cur, used);

        for(auto& ele : store) res.push_back(ele);
        return res;
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto num:nums) strs.push_back(to_string(num));
        auto cmp=[](string &s1, string &s2){ return s1+s2>s2+s1; };
        sort(strs.begin(),strs.end(),cmp);
        string ans="";
        for (auto s:strs) ans+=s;
        while (ans[0]=='0' && ans.length()!=1) {
            ans.erase(0,1);
        }
        return ans;
    }
};
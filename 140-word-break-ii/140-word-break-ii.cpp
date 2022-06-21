class Solution {
    unordered_map<string,vector<string>> m;
    unordered_set<string> sat;
    
    vector<string> helper(string s) {
        if (m.count(s)) return m[s];
        vector<string> ans;
        
        if (sat.count(s)) ans.push_back(s);
        
        for(int i=1; i<s.size(); i++) {
            string w=s.substr(i);
            if (sat.count(w)) {
                string r=s.substr(0,i);
                vector<string> p=helper(r);
                for(int i=0; i<p.size(); i++) {
                    p[i]+=" "+w;
                }
                ans.insert(ans.end(),p.begin(),p.end());
            }
        }
        m[s]=ans;
        return m[s];
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        sat=unordered_set<string>(wordDict.begin(),wordDict.end());
        return helper(s);
    }
};


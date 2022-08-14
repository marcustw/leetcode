class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        vector<int> counts(26,0);
        int maxFreq=0;
        for (char& c : s) {
            counts[c-'a']++;
            maxFreq=max(maxFreq,counts[c-'a']);
        }
        priority_queue<pair<int,char>> pq;
        for (int i=0; i<26; i++) {
            pq.push({counts[i],i+'a'});
        }
        vector<string> strs(maxFreq,"");
        int q=0;
        while (!pq.empty()) {
            pair<int,char> p=pq.top();
            pq.pop();
            for (int i=0; i<p.first; i++) {
                strs[q++]+=p.second;
                if (q==maxFreq) q=0;
            }
        }
        string ans=strs[0];
        for (int i=1; i<maxFreq; i++) {
            if (ans[ans.length()-1]==strs[i][0]) return "";
            ans+=strs[i];
        }
        return ans;
    }
};
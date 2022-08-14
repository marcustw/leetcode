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
        unordered_set<int> maxChars;
        vector<string> strs(maxFreq,"");
        int q=0;
        for (int i=0; i<26; i++) {
            if (counts[i]==maxFreq) {
                maxChars.insert(i);
                for (int j=0; j<maxFreq; j++) strs[j]+=(i+'a');
            }
        }
        for (int i=0; i<26; i++) {
            if (maxChars.count(i)) continue;
            for (int j=0; j<counts[i]; j++) {
                strs[q++]+=(i+'a');
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
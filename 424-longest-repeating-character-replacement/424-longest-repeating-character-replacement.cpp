class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        unordered_map<int,int> m;
        int maxfreq=0;
        int i=0;
        for (int j=0; j<s.length(); j++) {
            m[s[j]]++;
            maxfreq=max(maxfreq,m[s[j]]);
            if (j-i+1-maxfreq>k) {
                m[s[i]]--;
                i++;
            } else {
                ans=max(ans,j-i+1);
            }
              
        }
        return ans;
    }
};
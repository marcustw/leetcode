class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if (n<=1) return n;
        int ans=0;
        int i=0, j=0;
        unordered_map<char,int> m;
        int count=0;
        while (j<n) {
            if (!m[s[j]]) {
                m[s[j]]++;
                count++;
                j++;
            } else {
                ans=max(count,ans);
                m[s[i]]=0;
                i++;
                count--;
            }
        }
        ans=max(count,ans);
        return ans;
    }
};
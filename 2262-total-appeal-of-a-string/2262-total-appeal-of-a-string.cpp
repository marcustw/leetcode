class Solution {
public:
    long long appealSum(string s) {
        long long ans=0;
        int n=s.length();
        vector<int> m(26, -1);
        for (int i=0; i<n; i++) {
            ans += (i - m[s[i]-'a']) * (n - i);
            m[s[i]-'a']=i;
        }
        return ans;
    }
};
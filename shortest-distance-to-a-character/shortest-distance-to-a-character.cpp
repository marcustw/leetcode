class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.length(), pos=-n;
        vector<int> ans(n, INT_MAX);
        for (int i=0; i<n; i++) {
            if (s[i]==c) pos=i;
            ans[i]=i-pos;
        }
        for (int j=pos-1; j>=0; j--) {
            if (s[j]==c) pos=j;
            ans[j]=min(ans[j], pos-j);
        }
        return ans;
    }
};
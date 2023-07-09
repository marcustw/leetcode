class Solution {
public:
    int largestVariance(string s) {
        int ans=0;
        vector<int> chars(26,0);
        for (const char& c : s) chars[c-'a']++;
        for (int a=0; a<26; ++a) {
            for (int b=0; b<26; ++b) {
                int remA = chars[a];
                int remB = chars[b];
                if (a==b || remA==0 || remB==0) continue;

                int curA=0, curB=0;
                for (const char& ch : s) {
                    int c = ch-'a';
                    if (c==b) ++curB;
                    if (c==a) {
                        ++curA;
                        --remA;
                    }
                    if (curA>0)
                        ans = max(ans, curB-curA);
                    if (curB<curA && remA>=1) {
                        curB=0, curA=0;
                    }
                }
            }
        }
        return ans;
    }
};
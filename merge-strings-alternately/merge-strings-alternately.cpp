class Solution {
public:
    string mergeAlternately(string& word1, string& word2) {
        string ans="";
        int n=word1.length(), m=word2.length(), l=min(n,m);
        for (int i=0; i<l; ++i) {
            ans+=word1[i];
            ans+=word2[i];
        }
        if (n!=m) ans+=(n>m ? word1.substr(m, n-m) : word2.substr(n, m-n));
        return ans;
    }
};
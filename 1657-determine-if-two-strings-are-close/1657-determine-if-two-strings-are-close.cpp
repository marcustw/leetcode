class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        if (m!=n) return false;
        vector<int> m1(26, 0), m2(26, 0), m3(26, 0);
        for (char& c : word1) {
            m1[c-'a']++;
            m3[c-'a']=1;
        }
        for (char& c : word2) {
            m2[c-'a']++;
            m3[c-'a']=0;
        }
        sort(m1.begin(), m1.end());
        sort(m2.begin(), m2.end());
        for (int i=0; i<26; i++) {
            if (m3[i]==1) return false;
        }
        return m1 == m2;
    }
};
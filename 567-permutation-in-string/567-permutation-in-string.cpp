class Solution {
    bool checkVector(vector<int>& c1, vector<int>& c2) {
        for (int i=0; i<26; i++) {
            if (c1[i]!=c2[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> c1(26,0);
        vector<int> c2(26,0);
        int n=s1.length();
        for (int i=0; i<n; i++) {
            c1[s1[i]-'a']++;
        }
        int lo=0;
        int hi=0;
        while (hi<s2.length()) {
            c2[s2[hi++]-'a']++;
            if (hi-lo==n) {
                if (checkVector(c1,c2)) {
                    return true;
                }
                else {
                    c2[s2[lo++]-'a']--;
                }
            }
        }
        return false;
    }
};
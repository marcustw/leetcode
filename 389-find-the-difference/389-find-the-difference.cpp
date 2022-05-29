class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans=0;
        // sum(t) - sum(s) = diff
        for(char x: t)
            ans+=x;
        for (char x: s)
            ans-=x;
        return char(ans); 
    }
};
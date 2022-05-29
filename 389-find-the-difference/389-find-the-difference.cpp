class Solution {
public:
    char findTheDifference(string s, string t) {
         int ans=0;
        for(char x: t)
            ans+=x;
        for (char x: s)
            ans-=x;
        return char(ans); 
    }
};
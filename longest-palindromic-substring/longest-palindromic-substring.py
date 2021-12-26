class Solution:
    def longestPalindrome(self, s: str) -> str:
        l = len(s)
        if (l <= 1):
            return s
        
        res = ""
        
        for i in range(l):
            hi = i+1
            lo = i-1
            string1 = s[i]
            while (lo >= 0 and hi < l):
                if (s[lo] == s[hi]):
                    string1 = s[lo] + string1 + s[lo]
                else:
                    break
                lo -= 1
                hi += 1
            
            string2 = s[i]
            if (i+1 < l and s[i+1] == s[i]):
                string2 += s[i+1]
                hi = i+2
                lo = i-1
                while (lo >= 0 and hi < l):
                    if (s[lo] == s[hi]):
                        string2 = s[lo] + string2 + s[hi]
                    else:
                        break
                    lo -= 1
                    hi += 1
            
            if (len(string1) > len(res)):
                res = string1
            if (len(string2) > len(res)):
                res = string2
        
        return res
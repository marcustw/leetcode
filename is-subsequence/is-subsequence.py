class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i,j = 0,0
        n = len(s)
        if n == 0:
            return True
        for k in range(len(t)):
            if t[k] == s[i]:
                i += 1
            if i == n:
                return True
        return False 
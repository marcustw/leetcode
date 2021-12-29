class Solution:
    def romanToInt(self, s: str) -> int:
        res = 0
        j = 0
        k = 0
        for i in range(len(s)):
            c = s[i]
            if (c == "I"):
                j = 1
            elif (c == "V"):
                j = 5
            elif (c == "X"):
                j = 10
            elif (c == "L"):
                j = 50
            elif (c == "C"):
                j = 100
            elif (c == "D"):
                j = 500
            elif (c == "M"):
                j = 1000
            
            if j > k:
                res = res + j - (2 * k)
            else:
                res += j
            k = j
            
        return res
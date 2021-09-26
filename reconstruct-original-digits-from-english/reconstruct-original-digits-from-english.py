class Solution:
    # ZERO -> Z
    # TWO -> W
    # FOUR -> U
    # SIX -> X
    # EIGHT -> G
    # ONE -> num(O) - num(ZERO) - num(TWO) - num(FOUR)
    # THREE -> num(H) - num(EIGHT)
    # FIVE -> num(F) - num(FOUR)
    # SEVEN -> num(S) - num(SIX)
    # NINE -> num(I) - num(FIVE) - num(SIX) - num(EIGHT)
    def originalDigits(self, s: str) -> str:
        dic = {}
        for i in s:
            if (i in dic):
                dic[i] = dic[i] + 1
            else:
                dic[i] = 1
    
        digits = [0] * 10
        if ('z' in dic):
            digits[0] = dic['z']
        if ('w' in dic):
            digits[2] = dic['w']
        if ('u' in dic):
            digits[4] = dic['u']
        if ('x' in dic):
            digits[6] = dic['x']
        if ('g' in dic):
            digits[8] = dic['g']
        if ('o' in dic):
            digits[1] = dic['o'] - digits[0] - digits[2] - digits[4]
        if ('h' in dic):
            digits[3] = dic['h'] - digits[8]
        if ('f' in dic):
            digits[5] = dic['f'] - digits[4]
        if ('s' in dic):
            digits[7] = dic['s'] - digits[6]
        if ('i' in dic):
            digits[9] = dic['i'] - digits[5] - digits[6] - digits[8]
        
        res = ""
        for i in range(10):
            for j in range(digits[i]):
                res += str(i)
        return res
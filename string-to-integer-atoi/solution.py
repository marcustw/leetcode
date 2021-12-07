class Solution:
    
    def myAtoi(self, s: str) -> int:
        lowerLimit = - 2 ** 31
        upperLimit = (2 ** 31) - 1
        ans = 0
        isNegative = False
        hasSign = False
        hasDigits = False
        for i in range(len(s)):
            if (s[i] != '-' and s[i] != '+' and s[i] != ' ' and not s[i].isnumeric()):
                break
            else:
                if (s[i].isnumeric()):
                    hasDigits = True
                if (s[i] == ' '):
                    if (hasDigits or hasSign):
                        break
                    else:
                        continue
                if (s[i] == '-' or s[i] == '+') and hasDigits:
                    break
                if (s[i] == '-' or s[i] == '+') and hasSign:
                    break
                if (s[i] == '-'):
                    isNegative = True
                    hasSign = True
                elif (s[i] == '+'):
                    isNegative = False
                    hasSign = True
                else:
                    ans = ans * 10 + int(s[i])
        if (isNegative):
            ans = -1 * ans
        if ans < lowerLimit:
            return lowerLimit
        if ans > upperLimit:
            return upperLimit
        return ans

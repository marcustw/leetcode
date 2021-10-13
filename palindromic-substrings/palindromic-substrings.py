class Solution:
    def countSubstrings(self, s: str) -> int:
        l = len(s)
        dp = []
        for i in range(l):
            x = []
            for j in range(l):
                x.append(0)
            dp.append(x)
        dic = []
        count = 0
        for i in range(l):
            for j in range(i+1):
                if s[i] == s[j]:
                    print(s[i], s[j])
                    if (i - j < 2):
                        dp[j][i] = 1
                    else:
                        dp[j][i] = dp[j+1][i-1]
                if (dp[j][i] == 1):
                    dic.append(s[j:i+1])
                    count += 1
        return count
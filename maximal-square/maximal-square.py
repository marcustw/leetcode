import math
class Solution:
    def maximalSquare(self, matrix:List[List[int]]):
        r = len(matrix)
        c = len(matrix[0])
        dp = []
        for i in range(r):
            dp.append([])
            for j in range(c):
                dp[i].append(0)
        
        largest = 0
        for i in range(c):
            dp[0][i] = int(matrix[0][i])
            largest = max(largest, dp[0][i])     
        
        for i in range(1, r):
            for j in range(c):
                e = int(matrix[i][j])
                if (j == 0):
                    dp[i][j] = e
                elif e == 0:
                    dp[i][j] = 0
                else:
                    up = dp[i-1][j]
                    left = dp[i][j-1]
                    upleft = dp[i-1][j-1]
                    dp[i][j] = min(up, left, upleft) + 1
                largest = max(largest, dp[i][j])
        return largest ** 2
        
        
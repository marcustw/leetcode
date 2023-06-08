class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        i = 0
        j = n - 1
        count = 0
        
        while i < m and j >= 0:
            if grid[i][j] < 0:
                count += (m - i)
                j -= 1
            elif grid[i][j] >= 0:
                i += 1
        
        return count
class Solution:
    def helper(self, nums: List[int], index, mem) -> int:
        length = len(nums)
        if (mem[index] != -1):
            return mem[index]
        else:
            if (length == 0):
                return 0
            elif (length == 1):
                mem[index] = nums[0]
                return mem[index]
            elif (length == 2):
                mem[index] = max(nums[0], nums[1])
                return mem[index]
            else:
                mem[index] = max(nums[0] + self.helper(nums[2:], index + 2, mem), self.helper(nums[1:], index + 1, mem))
                return mem[index]
                
    
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if (n == 0):
            return 0
        elif (n == 1):
            return nums[0]
        elif (n == 2):
            return max(nums[0], nums[1])
        else:
            mem = [-1 for i in range(n)]
            mem2 = [-1 for i in range(n)]
            return max(self.helper(nums[:n-1], 0, mem), self.helper(nums[1:], 0, mem2))
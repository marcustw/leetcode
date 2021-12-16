class Solution:
    
    def helper(self, nums: List[int], index, mem) -> int:
        n = len(nums)
        if (mem[index] != -1):
            return mem[index]
        if (n == 0):
            mem[index] = 0
        elif (n == 1):
            mem[index] = nums[0]
        elif (n == 2):
            mem[index] = max(nums[0], nums[1])
        else:
            mem[index] = max(nums[0] + self.helper(nums[2:], index + 2, mem), self.helper(nums[1:], index + 1, mem))
        return mem[index]
    
    def rob(self, nums: List[int]) -> int:
        if (len(nums) == 0):
            return 0
        elif (len(nums) == 1):
            return nums[0]
        mem = [-1 for i in range(101)]
        return self.helper(nums, 0, mem)
            
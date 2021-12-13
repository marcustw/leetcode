class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        num0 = 0
        num1 = 0
        num2 = 0
        
        for i in range(len(nums)):
            if (nums[i] == 0):
                num0 += 1
            if (nums[i] == 1):
                num1 += 1
            if (nums[i] == 2):
                num2 += 1
        
        for i in range(len(nums)):
            if (num0 > 0):
                nums[i] = 0
                num0 -= 1
            elif (num1 > 0):
                nums[i] = 1
                num1 -= 1
            else:
                nums[i] = 2
                num2 -= 1
        
        return nums
        
        
        
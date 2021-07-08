class Solution:
    def threeSum(self, nums):
        nums.sort() # O(n log n)
        result = set()
        n = len(nums)
        for i in range(n): # O(n^2)
            hi = n - 1
            lo = i + 1
            if i > 0 and nums[i] == nums[i-1]:
                continue

            while (lo < hi):
                total = nums[i] + nums[lo] + nums[hi]
                if (total == 0):
                    result.add(tuple(sorted([nums[i], nums[lo], nums[hi]])))
                    hi-= 1
                    lo+= 1
                elif total > 0:
                    hi-= 1
                else:
                    lo+= 1
                
        return result

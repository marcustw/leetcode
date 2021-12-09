class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        if (len(nums) == 3):
            return sum(nums)
        nums = sorted(nums)
        
        minDiff = 2* 10 ** 4
        d = 1
        for i in range(len(nums) - 2):
            n = nums[i]
            lo = i + 1
            hi = len(nums) - 1
            while (lo < hi):
                total = n + nums[lo] + nums[hi]
                if (total == target):
                    return total
                if (total < target):
                    lo += 1
                else:
                    hi -= 1
                diff = abs(total - target)
                if (diff < minDiff):
                    minDiff = diff
                    if (total - target < 0):
                        d = -1
                    else:
                        d = 1
        # print(minDiff, d)
        return (d * minDiff) + target
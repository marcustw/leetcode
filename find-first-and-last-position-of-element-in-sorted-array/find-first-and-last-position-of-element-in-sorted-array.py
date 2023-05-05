class Solution:
    def binSearch(self, nums: List[int], target: int, lo: int, hi: int) -> int:
        while (lo<=hi):
            mid = lo + (hi-lo)//2
            if nums[mid] >= target:
                hi = mid-1
            else:
                lo = mid+1
        return lo

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        if n==0:
            return [-1, -1]
        lo = self.binSearch(nums, target, 0, n-1)
        hi = self.binSearch(nums, target+1, lo, n-1) - 1
        if lo < 0 or lo >= n or hi < 0 or hi >= n or nums[lo] != target or nums[hi] != target:
            return [-1, -1]
        return [lo, hi]
        
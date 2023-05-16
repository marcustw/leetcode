class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        n = len(nums)
        forward = nums.copy()
        for i in range(1,n):
            forward[i]+=forward[i-1]
        for i in reversed(range(0, n-1)):
            nums[i]+=nums[i+1]
        for i in range(n):
            prev = 0 if (i==0) else forward[i-1]
            rear = 0 if (i==n-1) else nums[i+1]
            if prev == rear:
                return i
        return -1
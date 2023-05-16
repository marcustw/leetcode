from typing import Tuple
class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1 = deque(sorted(nums1))  # O(n logn)
        nums = [[-x,i] for i, x in enumerate(nums2)]
        nums.sort()
        for x, i in nums:
            nums2[i] = nums1.pop() if -x < nums1[-1] else nums1.popleft()
        return nums2

class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        len1 = len(nums1)
        len2 = len(nums2)

        if (len1 > len2):
            return self.findMedianSortedArrays(nums2, nums1)
        
        lo = 0
        hi = len(nums1)
        total = len(nums1) + len(nums2)

        while (lo <= hi):
            p1 = int((lo + hi) / 2)
            x1 = self.getNum(nums1, True, p1)
            y1 = self.getNum(nums1, False, p1)

            p2 = int((total + 1) / 2) - p1
            x2 = self.getNum(nums2, True, p2)
            y2 = self.getNum(nums2, False, p2)

            if (x1 <= y2 and x2 <= y1):
                if (total % 2 == 0):
                    return (max(x1, x2) + min(y1, y2)) / 2
                else:
                    return max(x1, x2)
            
            if (x1 > y2):
                hi = p1 - 1
            else:
                lo = p1 + 1
        
        return nums1[0]

    def getNum(self, arr, isMax, partition):
        if (isMax):
            if (partition <= 0):
                return float('-inf')
            else:
                return arr[partition - 1]
        else:
            if (partition >= len(arr)):
                return float('inf')
            else:
                return arr[partition]
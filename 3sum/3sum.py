class Solution:
    def threeSum(self, nums):
        nums2 = sorted(nums)
        mem = dict()
        for x in nums2:
            y = str(x)
            if (y not in mem.keys()):
                mem[y] = 1
            else:
                mem[y]+= 1
        result = set()
        for i in range(len(nums2)):
            first = nums2[i]
            for j in range(i+1, len(nums2)):
                second = nums2[j]
                query = 0 - first - second
                key = str(query)
                if (key in mem.keys()):
                    check = True
                    if (first == query and second == query):
                        check = mem[key] > 2
                    elif (first == query or second == query):
                        check = mem[key] > 1
                    if check:    
                        result.add(tuple(sorted([first, second, query])))
        return result
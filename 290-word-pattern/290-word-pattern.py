class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        arr = s.split(' ')
        n = len(arr)
        l = len(pattern)
        
        if (n != l):
            return False
        map1 = {}
        map2 = {}
        for i in range(n):
            if (arr[i] not in map1):
                map1[arr[i]] = pattern[i]
            else:
                if (map1[arr[i]] != pattern[i]):
                    return False
            if (pattern[i] not in map2):
                map2[pattern[i]] = arr[i]
            else:
                if (map2[pattern[i]] != arr[i]):
                    return False
        
        return True
        
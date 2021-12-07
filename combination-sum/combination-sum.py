import copy

class Solution:
    
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        
        l = len(candidates)
        
        def dfs(arr, index, target2):
            if (target2 < 0):
                return
            if (target2 == 0):
                ar = copy.deepcopy(arr)
                res.append(ar)
                return
            for i in range(index, l):
                c = candidates[i]
                arr.append(c)
                dfs(arr, i, target2 - c)
                arr.pop()
        
        dfs([], 0, target)
        
        return res
            
            
class DisjointSet:
    def __init__(self, n: int):
        self.v = [i for i in range(1, n+1)]
    
    def find(self, x):
        if self.v[x-1] != x:
            self.v[x-1] = self.find(self.v[x-1])
        return self.v[x-1]
    
    def union(self, x, y):
        fx, fy = self.find(x), self.find(y)
        if (fx!=fy):
            self.v[fx-1] = fy
            return False
        return True


class Solution:
    # min span tree
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        ds = DisjointSet(len(edges))
        for edge in edges:
            if ds.union(edge[0], edge[1]):
                return edge
        return edges[-1]

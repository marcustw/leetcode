class Solution:
    def maxPoints(self, points) -> int:
        length = len(points)
        if (length <= 2):
            return length;
        largest = 0
        for i in range(0, length - 2):
            p1 = points[i]
            x1 = p1[0]
            y1 = p1[1]
            
            
            for j in range(i + 1, length - 1):
                p2 = points[j]
                x2 = p2[0]
                y2 = p2[1]
                
                count = 2
                for k in range(j + 1, length):
                    p3 = points[k]
                    x3 = p3[0]
                    y3 = p3[1]
                    
                    if (((y3 - y1) * (x2 - x1)) == ((y2 - y1) * (x3 - x1))):
                        count += 1
                largest = max(count, largest)
        return largest

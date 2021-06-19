class Solution:
    def maxPoints(self, points) -> int:
        length = len(points)
        if (length <= 2):
            return length;
        else:
            largest = 1
            mem = {}
            vert = {}            
            for i in range(0, length):
                for j in range(i, length):
                    a = points[i]
                    b = points[j]
                    dy = a[1] - b[1]
                    dx = a[0] - b[0]
                    if (dx == 0):
                        x = a[0]
                        if x not in vert:
                            count = 0
                            for point in points:
                                if point[0] == x:
                                    count = count + 1
                            vert[x] = count
                            if count > largest:
                                largest = count
                    else:
                        gradient = float(dy)/dx
                        c1 = b[1] - (gradient * b[0])
                        c2 = a[1] - (gradient * a[0])
                        cavg = (c1 + c2) / 2.0
                        c = round(cavg, 12)
                        ground = round(gradient, 12)
                        if ground not in mem:
                            mem[ground] = {}
                        if c not in mem[ground]:
                            count = 0
                            #print('===========')
                            #print('m = ', gradient, '  , c= ', c)
                            for point in points:
                                x = point[0]
                                y = point[1]
                                #print('===========')
                                if (abs(y - ((gradient * x) + cavg)) <= 0.000000000001):
                                    #print(point)
                                    #print(y - ((gradient * x) + c))
                                    count = count + 1
                            mem[ground][c] = count
                            if count > largest:
                                largest = count
            # print(mem)
            return largest
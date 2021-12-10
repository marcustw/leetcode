class Solution:
    def flip(self, i):
        if (i < 0):
            return abs(i)
        else:
            return -i
    
    def divide(self, dividend: int, divisor: int) -> int:
        lowest = -2147483648
        highest = 2147483647
        
        if (dividend == lowest and divisor == -1):
            return highest
        if (divisor == 1):
            return dividend
        if (dividend < 0):
            return -self.divide(-dividend, divisor)
        if (divisor < 0):
            return -self.divide(dividend, -divisor)
        if (dividend < divisor or dividend == 0):
            return 0
        
        multiple = 1
        total = divisor
        while((total + total) < dividend):
            multiple += multiple
            total += total
        return multiple + self.divide(dividend - total, divisor)
        
class Solution:
    def reverse(self, x: int) -> int:
        largest = 2147483647
        smallest = -2147483648
        sign = 1
        if (x < 0):
            sign = -1
        y = sign * x
        y = str(y)
        y = y[::-1]
        y = sign * int(y)
        if (y > largest or y < smallest):
            return 0
        return y
        
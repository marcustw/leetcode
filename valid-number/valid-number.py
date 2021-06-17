# Import math Library
import math

class Solution:
    def isNumber(self, s: str) -> bool:
        try:
            val = float(s)
            if (math.isinf(val)):
                return "inf" not in s.lower()
            elif (type(val) is float):
                return True
            else:
                return False
        except:
            return False

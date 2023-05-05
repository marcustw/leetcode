class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        ans, tmp = 0, 0
        vowels = ['a', 'e', 'i', 'o', 'u']
        lo, hi = 0, 0
        size = 0
        while (hi<len(s)):
            if size<k:
                tmp += 1 if s[hi] in vowels else 0
                hi += 1
                size += 1
                ans = max(tmp, ans)
            elif size==k:
                tmp -= 1 if s[lo] in vowels else 0
                lo += 1
                size -= 1

        return ans


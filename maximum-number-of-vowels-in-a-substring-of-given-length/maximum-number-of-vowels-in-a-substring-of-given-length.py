class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = ['a', 'e', 'i', 'o', 'u']
        ans = tmp = 0
        for i, c in enumerate(s):
            if c in vowels:
                tmp += 1
            if i>=k and s[i-k] in vowels:
                tmp -= 1
            ans = max(tmp, ans)
        return ans

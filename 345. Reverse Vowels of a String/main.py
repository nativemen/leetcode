class Solution:
    def reverseVowels(self, s: str) -> str:
        def isEmpty(c: chr) -> bool:
            return c in "aeiouAEIOU"

        t = list(s)
        size = len(t)
        left = 0
        right = size - 1

        while left < right:
            while left < size and not isEmpty(t[left]):
                left += 1

            while right >= 0 and not isEmpty(t[right]):
                right -= 1

            if left < right:
                t[left], t[right] = t[right], t[left]
                left += 1
                right -= 1

        return "".join(t)


class Solution:
    def reverseVowels(self, s: str) -> str:
        def isEmpty(c: chr) -> bool:
            return c in "aeiouAEIOU"

        t = list(s)
        size = len(t)
        left = 0
        right = size - 1

        while left < right:
            if not isEmpty(t[left]):
                left += 1

            if not isEmpty(t[right]):
                right -= 1

            if isEmpty(t[left]) and isEmpty(t[right]):
                t[left], t[right] = t[right], t[left]
                left += 1
                right -= 1

        return "".join(t)


class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = "aeiouAEIOU"
        t = list(s)
        size = len(t)
        left = 0
        right = size - 1

        while left < right:
            if t[left] not in vowels:
                left += 1

            if t[right] not in vowels:
                right -= 1

            if t[left] in vowels and t[right] in vowels:
                t[left], t[right] = t[right], t[left]
                left += 1
                right -= 1

        return "".join(t)
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        count = 0
        next = " "

        for c in s[::-1]:
            if next != " " and c == " ":
                break

            if c != " ":
                count += 1

            next = c

        return count


class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        return len(s.split()[-1])

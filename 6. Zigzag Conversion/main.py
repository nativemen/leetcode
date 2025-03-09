class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        direction = -1
        level = 0
        size = len(s)
        rows = [""] * numRows

        for i in range(size):
            rows[level] += s[i]
            if level % (numRows - 1) == 0:
                direction *= -1
            level += direction

        return "".join(rows)


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        size = len(s)
        result = ""

        for i in range(0, numRows):
            for j in range(i, size, 2 * (numRows - 1)):
                result += s[j]
                if i > 0 and i < numRows - 1 and j + 2 * (numRows - 1) - 2 * i < size:
                    result += s[j + 2 * (numRows - 1) - 2 * i]

        return result

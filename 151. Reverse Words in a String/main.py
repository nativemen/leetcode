class Solution:
    def reverseWords(self, s: str) -> str:
        words = []
        word = ""

        for c in s[::-1]:
            if c != " ":
                word = c + word
            else:
                if word != "":
                    words.append(word)
                    word = ""

        if word != "":
            words.append(word)

        result = ""

        for word in words:
            if len(result) != 0:
                result += " "

            result += word

        return result


class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s.split()[::-1])


class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(reversed(s.split()))


class Solution:
    def reverseWords(self, s: str) -> str:
        words = []
        size = len(s)
        start = 0
        delimiter = " "
        end = s.find(delimiter)

        while end != -1:
            if end != start:
                words.append(s[start:end])

            start = end + 1
            end = s.find(delimiter, start)

        if start != size:
            words.append(s[start:])

        result = ""

        for word in words[::-1]:
            if len(result) != 0:
                result += " "

            result += word

        return result


class Solution:
    def reverseWords(self, s: str) -> str:
        size = len(s)
        start = 0
        count = 0
        result = ""

        for i in range(size - 1, -1, -1):
            if s[i] != " ":
                count += 1
                if i == 0 or s[i - 1] == " ":
                    result += s[i : i + count]
                    result += " "
                    count = 0

        if result[-1] == " ":
            return result[:-1]

        return result

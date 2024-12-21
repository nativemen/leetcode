class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        text = ""
        strLen = len(s)
        for i in range(0, strLen, 2 * k):
            minLen = min(k, strLen - i)
            text += s[i : i + minLen][::-1]
            text += s[i + minLen : i + 2 * k]

        return text


class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        str_list = list()

        for i in range(0, len(s), 2 * k):
            str_list.append(s[i : i + k][::-1])
            str_list.append(s[i + k : i + 2 * k])

        return "".join(str_list)


class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        str_list = list(s)

        for i in range(0, len(s), 2 * k):
            str_list[i : i + k] = str_list[i : i + k][::-1]

        return "".join(str_list)

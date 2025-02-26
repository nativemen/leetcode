class Solution:
    def romanToInt(self, s: str) -> int:
        size = len(s)
        prev = "\0"
        result = 0

        for i in range(size):
            match s[i]:
                case "I":
                    result += 1
                case "V":
                    if prev == "I":
                        result += 4 - 1
                    else:
                        result += 5
                case "X":
                    if prev == "I":
                        result += 9 - 1
                    else:
                        result += 10
                case "L":
                    if prev == "X":
                        result += 40 - 10
                    else:
                        result += 50
                case "C":
                    if prev == "X":
                        result += 90 - 10
                    else:
                        result += 100
                case "D":
                    if prev == "C":
                        result += 400 - 100
                    else:
                        result += 500
                case "M":
                    if prev == "C":
                        result += 900 - 100
                    else:
                        result += 1000
                case _:
                    result += 0

            prev = s[i]

        return result


class Solution:
    def romanToInt(self, s: str) -> int:
        size = len(s)
        result = 0
        prev = 0
        cur = 0

        for i in range(size - 1, -1, -1):
            cur = self.romanToValue(s[i])
            if cur >= prev:
                result += cur
            else:
                result -= cur

            prev = cur

        return result

    def romanToValue(self, c: chr) -> int:
        match c:
            case "I":
                return 1
            case "V":
                return 5
            case "X":
                return 10
            case "L":
                return 50
            case "C":
                return 100
            case "D":
                return 500
            case "M":
                return 1000
            case _:
                return 0


class Solution:
    def romanToInt(self, s: str) -> int:
        roman_dicts = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }
        size = len(s)
        result = 0
        prev = 0
        cur = 0

        for i in range(size - 1, -1, -1):
            cur = roman_dicts[s[i]]
            if cur >= prev:
                result += cur
            else:
                result -= cur

            prev = cur

        return result

class Solution:
    def intToRoman(self, num: int) -> str:
        s = ""

        while num > 0:
            if num >= 1000:
                s += "M"
                num -= 1000
            elif num >= 900:
                s += "CM"
                num -= 900
            elif num >= 500:
                s += "D"
                num -= 500
            elif num >= 400:
                s += "CD"
                num -= 400
            elif num >= 100:
                s += "C"
                num -= 100
            elif num >= 90:
                s += "XC"
                num -= 90
            elif num >= 50:
                s += "L"
                num -= 50
            elif num >= 40:
                s += "XL"
                num -= 40
            elif num >= 10:
                s += "X"
                num -= 10
            elif num >= 9:
                s += "IX"
                num -= 9
            elif num >= 5:
                s += "V"
                num -= 5
            elif num >= 4:
                s += "IV"
                num -= 4
            else:
                s += "I"
                num -= 1

        return s


class Solution:
    def intToRoman(self, num: int) -> str:
        symbols = [
            "M",
            "CM",
            "D",
            "CD",
            "C",
            "XC",
            "L",
            "XL",
            "X",
            "IX",
            "V",
            "IV",
            "I",
        ]
        values = [
            1000,
            900,
            500,
            400,
            100,
            90,
            50,
            40,
            10,
            9,
            5,
            4,
            1,
        ]

        s = ""
        index = 0

        while num > 0:
            while num >= values[index]:
                s += symbols[index]
                num -= values[index]

            index += 1

        return s


class Solution:
    def intToRoman(self, num: int) -> str:
        tables = [
            (1000, "M"),
            (900, "CM"),
            (500, "D"),
            (400, "CD"),
            (100, "C"),
            (90, "XC"),
            (50, "L"),
            (40, "XL"),
            (10, "X"),
            (9, "IX"),
            (5, "V"),
            (4, "IV"),
            (1, "I"),
        ]

        s = ""
        index = 0

        while num > 0:
            while num >= tables[index][0]:
                s += tables[index][1]
                num -= tables[index][0]

            index += 1

        return s


class Solution:
    def intToRoman(self, num: int) -> str:
        tables = [
            (1000, "M"),
            (900, "CM"),
            (500, "D"),
            (400, "CD"),
            (100, "C"),
            (90, "XC"),
            (50, "L"),
            (40, "XL"),
            (10, "X"),
            (9, "IX"),
            (5, "V"),
            (4, "IV"),
            (1, "I"),
        ]

        result = ""

        for value, s in tables:
            while num >= value:
                result += s
                num -= value

        return result


class Solution:
    def intToRoman(self, num: int) -> str:
        tables = [
            (1000, "M"),
            (900, "CM"),
            (500, "D"),
            (400, "CD"),
            (100, "C"),
            (90, "XC"),
            (50, "L"),
            (40, "XL"),
            (10, "X"),
            (9, "IX"),
            (5, "V"),
            (4, "IV"),
            (1, "I"),
        ]

        result = ""

        for value, s in tables.items():
            while num >= value:
                result += s
                num -= value

        return result

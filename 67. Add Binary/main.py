class Solution:
    def addBinary(self, a: str, b: str) -> str:
        result = ""

        index1 = len(a) - 1
        index2 = len(b) - 1
        carry = 0

        while index1 >= 0 or index2 >= 0 or carry > 0:
            digit1 = ord(a[index1]) - ord("0") if index1 >= 0 else 0
            digit2 = ord(b[index2]) - ord("0") if index2 >= 0 else 0
            sum = digit1 + digit2 + carry
            result += chr(ord("0") + (sum & 1))
            carry = sum >> 1
            index1 -= 1
            index2 -= 1

        return result[::-1]


class Solution:
    def addBinary(self, a: str, b: str) -> str:
        binaryA = int(a, 2)
        binaryB = int(b, 2)
        binaryRes = binaryA + binaryB

        return bin(binaryRes)[2:]


class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(a, 2) + int(b, 2))[2:]

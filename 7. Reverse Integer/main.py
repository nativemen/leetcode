class Solution:
    def c_style_mod(self, a, b):
        # Calculate the remainder using the modulo operator
        remainder = a % b

        # Adjust the remainder to match the sign of the divisor
        # If 'a' is negative and 'b' is positive, and the remainder is not zero
        if a < 0 and b > 0 and remainder != 0:
            remainder -= b

        return remainder

    def reverse(self, x: int) -> int:
        INT_MIN = -pow(2, 31)
        INT_MAX = pow(2, 31) - 1

        result = 0
        while x != 0:
            digit = int(self.c_style_mod(x, 10))

            if (
                result > int(INT_MAX / 10)
                or (
                    result == int(INT_MAX / 10)
                    and digit > int(self.c_style_mod(INT_MAX, 10))
                )
                or result < int(INT_MIN / 10)
                or (
                    result == int(INT_MIN / 10)
                    and digit < int(self.c_style_mod(INT_MIN, 10))
                )
            ):
                return 0
            result = result * 10 + digit
            x = int(x / 10)

        return result


class Solution:
    def reverse(self, x: int) -> int:
        INT_MIN = -pow(2, 31)
        INT_MAX = pow(2, 31) - 1

        digit_list = [digit for digit in str(x) if digit != "-"]
        digit_list.reverse()
        result = int("".join(digit_list))
        if x < 0:
            result = -result

        if result < INT_MIN or result > INT_MAX:
            return 0

        return result


class Solution:
    def reverse(self, x: int) -> int:
        INT_MIN = -pow(2, 31)
        INT_MAX = pow(2, 31) - 1

        if x >= 0:
            result = int(str(x)[::-1])
        else:
            result = -int(str(x)[1:][::-1])

        if result < INT_MIN or result > INT_MAX:
            return 0

        return result


class Solution:
    def reverse(self, x: int) -> int:
        result = int(str(abs(x))[::-1])

        if result.bit_length() > 31:
            return 0
        elif x < 0:
            return -result
        else:
            return result


class Solution:
    def reverse(self, x: int) -> int:
        INT_MIN = -pow(2, 31)
        INT_MAX = pow(2, 31) - 1
        result = int(str(abs(x))[::-1])

        if x < 0:
            if -result < INT_MIN:
                return 0
            return -result
        else:
            if result > INT_MAX:
                return 0
            return result

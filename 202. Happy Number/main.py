class Solution:
    def computeNext(self, n: int) -> int:
        sum = 0

        while n != 0:
            num = n % 10
            sum += num * num
            n //= 10

        return sum

    def isHappy(self, n: int) -> bool:
        history = [n]

        while True:
            num = self.computeNext(history[-1])
            if num == 1:
                return True

            if num in history:
                break

            history.append(num)

        return False


class Solution:
    def computeNext(self, n: int) -> int:
        sum = 0

        while n != 0:
            num = n % 10
            sum += num * num
            n //= 10

        return sum

    def isHappy(self, n: int) -> bool:
        history = set()

        while n not in history:
            if n == 1:
                return True

            history.add(n)
            n = self.computeNext(n)

        return False


class Solution:
    def computeNext(self, n: int) -> int:
        sum = 0

        while n != 0:
            num = n % 10
            sum += num * num
            n //= 10

        return sum

    def isHappy(self, n: int) -> bool:
        slow = n
        fast = n

        while fast != 1 and self.computeNext(fast) != 1:
            slow = self.computeNext(slow)
            fast = self.computeNext(self.computeNext(fast))

            if fast == slow:
                return False

        return True


class Solution:
    def isHappy(self, n: int) -> bool:
        if n == 1 or n == 7:
            return True

        if n < 10:
            return False

        sum = 0

        while n != 0:
            num = n % 10
            sum += num * num
            n //= 10

        return self.isHappy(sum)

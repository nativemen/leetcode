class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        num = 1

        while num <= n:
            if n % num == 0:
                k -= 1
                if k == 0:
                    return num

            num += 1

        return -1


class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        count = 0

        for i in range(1, n + 1):
            if n % i == 0:
                count += 1
                if count == k:
                    return i

        return -1


class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        fact = []

        for i in range(1, n + 1):
            if n % i == 0:
                fact.append(i)

        if k > len(fact):
            return -1

        return fact[k - 1]

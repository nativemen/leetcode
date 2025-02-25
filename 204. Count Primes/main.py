class Solution:
    def countPrimes(self, n: int) -> int:
        is_primes = [True] * n
        count = 0

        for i in range(2, n):
            if not is_primes[i]:
                continue
            count += 1

            for mult in range(i * i, n, i):
                is_primes[mult] = False

        return count


class Solution:
    def countPrimes(self, n: int) -> int:
        is_primes = [True] * n
        count = 0

        for i in range(2, n):
            if is_primes[i]:
                count += 1
                is_primes[i * i : n : i] = [False] * len(is_primes[i * i : n : i])

        return count

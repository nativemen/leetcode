from typing import List


class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        max_wealth = 0
        for customer in accounts:
            max_wealth = max(max_wealth, sum(customer))

        return max_wealth


class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        return max(sum(customer) for customer in accounts)

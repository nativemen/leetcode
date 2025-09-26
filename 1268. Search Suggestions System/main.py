from typing import List


class Solution:
    def suggestedProducts(
        self, products: List[str], searchWord: str
    ) -> List[List[str]]:
        products.sort()

        result = list()
        prefix = ""
        wordSize = len(searchWord)
        productsSize = len(products)

        for i in range(wordSize):
            matched = list()
            prefix += searchWord[i]

            for j in range(productsSize):
                if products[j].startswith(prefix):
                    matched.append(products[j])
                    if len(matched) >= 3:
                        break

            result.append(matched)

        return result


class Solution:
    def suggestedProducts(
        self, products: List[str], searchWord: str
    ) -> List[List[str]]:
        products.sort()

        result = list()
        productsSize = len(products)
        left = 0
        right = productsSize - 1

        for i, c in enumerate(searchWord):
            while left <= right and (
                len(products[left]) <= i or products[left][i] != c
            ):
                left += 1

            while left <= right and (
                len(products[right]) <= i or products[right][i] != c
            ):
                right -= 1

            remain = right - left + 1
            matched = list()
            for j in range(min(3, remain)):
                matched.append(products[left + j])

            result.append(matched)

        return result

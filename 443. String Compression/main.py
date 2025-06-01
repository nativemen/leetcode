from typing import List


class Solution:
    def compress(self, chars: List[str]) -> int:
        charsSize = len(chars)
        count = 1
        index = 0
        current = chars[0]

        for i in range(charsSize):
            if i + 1 == charsSize or chars[i] != chars[i + 1]:
                chars[index] = current
                index += 1

                if count > 1:
                    for c in str(count):
                        chars[index] = c
                        index += 1

                if i + 1 < charsSize:
                    current = chars[i + 1]
                    count = 1
            else:
                count += 1

        return index

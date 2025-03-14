from typing import List


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        wordLens = []

        for word in words:
            wordLens.append(len(word))

        result = []
        end = 0
        size = len(words)

        while end < size:
            lineLen = 0
            start = end

            while end < size and lineLen + len(words[end]) + end - start <= maxWidth:
                lineLen += len(words[end])
                end += 1

            numWords = end - start
            spaceSlots = numWords - 1
            totalSpaces = maxWidth - lineLen
            baseSpaces = 0 if spaceSlots == 0 else totalSpaces // spaceSlots
            extraSpaces = 0 if spaceSlots == 0 else totalSpaces % spaceSlots

            if end == size:
                baseSpaces = 0 if spaceSlots == 0 else 1
                extraSpaces = 0

            line = ""
            for i in range(start, end):
                line += words[i]
                if i < end - 1:
                    currentSpaces = (
                        baseSpaces if i - start >= extraSpaces else baseSpaces + 1
                    )
                    line += " " * currentSpaces

            line += " " * (maxWidth - len(line))

            result.append(line)

        return result


class Solution:
    def getLine(
        self,
        words: List[str],
        maxWidth,
        start: int,
        end: int,
        baseSpaces: int,
        extraSpaces: int,
    ) -> str:
        line = ""

        for i in range(start, end):
            line += words[i]
            if i < end - 1:
                currentSpaces = (
                    baseSpaces if i - start >= extraSpaces else baseSpaces + 1
                )

                line += " " * currentSpaces

        line += " " * (maxWidth - len(line))

        return line

    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        wordLens = []

        for word in words:
            wordLens.append(len(word))

        result = []
        end = 0
        size = len(words)

        while end < size:
            lineLen = 0
            start = end

            while end < size and lineLen + len(words[end]) + end - start <= maxWidth:
                lineLen += len(words[end])
                end += 1

            numWords = end - start
            spaceSlots = numWords - 1
            totalSpaces = maxWidth - lineLen
            baseSpaces = 0 if spaceSlots == 0 else totalSpaces // spaceSlots
            extraSpaces = 0 if spaceSlots == 0 else totalSpaces % spaceSlots

            if end == size:
                baseSpaces = 0 if spaceSlots == 0 else 1
                extraSpaces = 0

            result.append(
                self.getLine(words, maxWidth, start, end, baseSpaces, extraSpaces)
            )

        return result


class Solution:
    def leftRightJustify(self, row: List[str], maxWidth: int) -> str:
        wordLens = 0

        for word in row:
            wordLens += len(word)

        lineStr = ""
        numWords = len(row)
        totalSpaces = maxWidth - wordLens
        spaceSlots = numWords - 1
        if spaceSlots == 0:
            lineStr = row[0] + " " * totalSpaces
            return lineStr

        baseSpaces = totalSpaces // spaceSlots
        extraSpace = totalSpaces % spaceSlots

        for i in range(numWords):
            lineStr += row[i]
            if i < numWords - 1:
                currentSpaces = baseSpaces + 1 if i < extraSpace else baseSpaces
                lineStr += " " * currentSpaces

        return lineStr

    def leftJustify(self, row: List[str], maxWidth: int) -> str:
        lineStr = " ".join(row)
        lineStr += " " * (maxWidth - len(lineStr))

        return lineStr

    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        rows = []
        row = []
        rowLen = 0

        for word in words:
            if rowLen + len(word) <= maxWidth:
                row.append(word)
                rowLen += len(word) + 1
            else:
                rows.append(row)
                row = [word]
                rowLen = len(word) + 1

        if row:
            rows.append(row)

        result = []
        for i in range(len(rows) - 1):
            result.append(self.leftRightJustify(rows[i], maxWidth))

        result.append(self.leftJustify(rows[len(rows) - 1], maxWidth))

        return result

from collections import deque
from typing import List


class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        def gene2Hash(gene: str) -> int:
            hash = 0
            maps = {"A": 0, "C": 1, "G": 2, "T": 3}

            for i in range(8):
                hash = (hash << 2) | maps[gene[i]]

            return hash

        def findGeneMutations(geneHash: int) -> List[int]:
            geneMutations = []

            for i in range(8):
                mask = 3 << (i * 2)

                for j in range(4):
                    mutationHash = (geneHash & ~mask) | (j << (i * 2))

                    if mutationHash == geneHash:
                        continue

                    geneMutations.append(mutationHash)

            return geneMutations

        endGeneHash = gene2Hash(endGene)
        bankHashSet = set()

        for gene in bank:
            bankHashSet.add(gene2Hash(gene))

        q = deque()
        q.append(gene2Hash(startGene))

        steps = 0

        while q:
            size = len(q)

            for i in range(size):
                currentHash = q.popleft()

                if currentHash == endGeneHash:
                    return steps

                geneMutations = findGeneMutations(currentHash)

                for mutationHash in geneMutations:
                    if mutationHash in bankHashSet:
                        q.append(mutationHash)
                        bankHashSet.discard(mutationHash)

            steps += 1

        return -1


class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        def isValid(s1: str, s2: str) -> bool:
            if len(s1) != len(s2):
                return False

            diff = 0

            for i in range(len(s1)):
                if s1[i] != s2[i]:
                    diff += 1

            if diff == 1:
                return True

            return False

        if not bank:
            return -1

        used = [False] * len(bank)
        q = deque()

        for i, gene in enumerate(bank):
            if isValid(startGene, gene):
                q.append((i, 1))
                used[i] = True

        while q:
            (current, steps) = q.popleft()

            if bank[current] == endGene:
                return steps

            for index, gene in enumerate(bank):
                if not used[index] and isValid(bank[current], gene):
                    q.append((index, steps + 1))
                    used[index] = True

        return -1


class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        if not bank or endGene not in bank:
            return -1

        q = deque([(startGene, 0)])
        visited = set([startGene])
        genes = ["A", "C", "G", "T"]

        while q:
            (current, steps) = q.popleft()

            if current == endGene:
                return steps

            s = list(current)

            for i, c in enumerate(s):
                for gene in genes:
                    if gene == c:
                        continue

                    s[i] = gene
                    target = "".join(s)

                    if target not in visited and target in bank:
                        q.append((target, steps + 1))
                        visited.add(target)

                s[i] = c

        return -1

from collections import deque


class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        rq = deque()
        dq = deque()
        size = len(senate)

        for i in range(size):
            if senate[i] == "R":
                rq.append(i)
            else:
                dq.append(i)

        while rq and dq:
            r = rq.popleft()
            d = dq.popleft()

            if r < d:
                rq.append(r + size)
            else:
                dq.append(d + size)

        if not rq:
            return "Dire"

        return "Radiant"


class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        rq = []
        dq = []
        size = len(senate)

        for i in range(size):
            if senate[i] == "R":
                rq.append(i)
            else:
                dq.append(i)

        while rq and dq:
            r = rq.pop(0)
            d = dq.pop(0)

            if r < d:
                rq.append(r + size)
            else:
                dq.append(d + size)

        if not rq:
            return "Dire"

        return "Radiant"

from collections import defaultdict


class TimeMap:
    def __init__(self):
        self.maps = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.maps:
            self.maps[key] = []

        self.maps[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.maps:
            return ""

        item = self.maps[key]

        left, right = 0, len(item) - 1

        while left <= right:
            mid = (left + right) // 2

            if item[mid][0] <= timestamp:
                left = mid + 1
            else:
                right = mid - 1

        return item[right][1] if right >= 0 else ""


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)


class TimeMap:
    def __init__(self):
        self.maps = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.maps[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        result, item = "", self.maps[key]
        left, right = 0, len(item) - 1

        while left <= right:
            mid = (left + right) // 2

            if item[mid][0] <= timestamp:
                result = item[mid][1]
                left = mid + 1
            else:
                right = mid - 1

        return result


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)

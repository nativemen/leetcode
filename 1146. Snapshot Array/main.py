class SnapshotArray:
    def __init__(self, length: int):
        self.array = [[] for _ in range(length)]
        self.snap_id = 0

    def set(self, index: int, val: int) -> None:
        if index < 0 or index >= len(self.array):
            return

        self.array[index].append((self.snap_id, val))

    def snap(self) -> int:
        id = self.snap_id
        self.snap_id += 1

        return id

    def get(self, index: int, snap_id: int) -> int:
        if (
            index < 0
            or index >= len(self.array)
            or snap_id < 0
            or snap_id > self.snap_id
        ):
            return -1

        left, right = 0, len(self.array[index]) - 1
        result = 0

        while left <= right:
            mid = left + (right - left) // 2

            if self.array[index][mid][0] <= snap_id:
                result = self.array[index][mid][1]
                left = mid + 1
            else:
                right = mid - 1

        return result


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)

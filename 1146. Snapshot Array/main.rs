struct Solution;

struct SnapshotArray {
    array: Vec<Vec<(i32, i32)>>,
    snap_id: i32,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl SnapshotArray {

    fn new(length: i32) -> Self {
        Self {
            array: vec![vec![]; length as usize],
            snap_id: 0,
        }
    }

    fn set(&mut self, index: i32, val: i32) {
        if index < 0 || index > self.array.len() as i32 {
            return;
        }

        self.array[index as usize].push((self.snap_id, val));
    }

    fn snap(&mut self) -> i32 {
        self.snap_id += 1;

        self.snap_id - 1
    }

    fn get(&self, index: i32, snap_id: i32) -> i32 {
        if index < 0 || index > self.array.len() as i32 || snap_id < 0 || snap_id > self.snap_id {
            return -1;
        }

        let mut left = 0;
        let mut right = self.array[index as usize].len() as i32 - 1;
        let mut result = 0;

        while left <= right {
            let mid = left + (right - left) / 2;

            if self.array[index as usize][mid as usize].0 <= snap_id {
                result = self.array[index as usize][mid as usize].1;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        result
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * let obj = SnapshotArray::new(length);
 * obj.set(index, val);
 * let ret_2: i32 = obj.snap();
 * let ret_3: i32 = obj.get(index, snap_id);
 */
isBadVersion(version:i32)-> bool;

// The API isBadVersion is defined for you.
// isBadVersion(version:i32)-> bool;
// to call it use self.isBadVersion(version)

impl Solution {
    pub fn first_bad_version(&self, n: i32) -> i32 {
        let mut left = 1;
        let mut right = n;
        let mut first = -1;

        while left <= right {
            let mid = left + (right - left) / 2;
            if self.isBadVersion(mid) {
                first = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return first;
    }
}
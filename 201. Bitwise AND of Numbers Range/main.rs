struct Solution;

impl Solution {
    pub fn range_bitwise_and(left: i32, right: i32) -> i32 {
        let mut shift = 0;
        let mut left = left;
        let mut right = right;

        while left < right {
            left >>= 1;
            right >>= 1;
            shift += 1;
        }

        left << shift
    }
}

impl Solution {
    pub fn range_bitwise_and(left: i32, right: i32) -> i32 {
        let mut left = left;
        let mut right = right;

        while left < right {
            right &= right - 1;
        }

        right
    }
}

impl Solution {
    pub fn range_bitwise_and(left: i32, right: i32) -> i32 {
        (left..right).fold(right, |acc, num| acc & num)
    }
}

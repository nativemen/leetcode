struct Solution;

impl Solution {
    pub fn hamming_distance(x: i32, y: i32) -> i32 {
        let mut count = 0;
        let mut n = x ^ y;

        while (n != 0) {
            count += n & 1;
            n >>= 1;
        }

        count
    }
}

impl Solution {
    pub fn hamming_distance(x: i32, y: i32) -> i32 {
        (x ^ y).count_ones() as i32
    }
}
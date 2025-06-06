struct Solution;

impl Solution {
    pub fn hamming_weight(n: i32) -> i32 {
        let mut count = 0;
        let mut n = n;

        while (n != 0) {
            count += n & 1;
            n >>= 1;
        }

        count
    }
}

impl Solution {
    pub fn hamming_weight(n: i32) -> i32 {
        n.count_ones() as i32
    }
}

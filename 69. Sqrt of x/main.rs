struct Solution;

impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        let mut left = 0;
        let mut right = x;

        while left <= right {
            let mid = left + (right - left) / 2;
            let square = mid as i64 * mid as i64;

            if square == x as i64 {
                return mid;
            } else if square < x as i64 {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        right
    }
}

impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        let mut i = 0i64;

        while i * i <= x as i64 {
            i += 1;
        }

        (i - 1) as i32
    }
}

struct Solution;

impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        let mut left = 0i64;
        let mut right = x as i64;
        let mut result = 0;

        while left <= right {
            let mid = (left + right) / 2;
            let product = mid * mid;

            if product == x as i64 {
                result = mid as i32;
                break;
            } else if product < x as i64 {
                result = mid as i32;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        result
    }
}

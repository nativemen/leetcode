struct Solution;

impl Solution {
    pub fn is_perfect_square(num: i32) -> bool {
        for i in 1..=num as i64 {
            let square = i * i;
            if square == num as i64 {
                return true;
            } else if square > num as i64 {
                break;
            }
        }

        false
    }
}

impl Solution {
    pub fn is_perfect_square(num: i32) -> bool {
        let mut left = 1 as i64;
        let mut right = num as i64;

        while left <= right {
            let mid = left + (right - left) / 2;
            let square = mid * mid;

            if square == num as i64 {
                return true;
            } else if square < num as i64 {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        false
    }
}

use std::cmp::Ordering::*;

impl Solution {
    pub fn is_perfect_square(num: i32) -> bool {
        let mut left = 1 as i64;
        let mut right = num as i64;

        while left <= right {
            let mid = left + (right - left) / 2;

            match (mid * mid).cmp(&(num as i64)) {
                Equal => return true,
                Less => left = mid + 1,
                Greater => right = mid - 1,
            }
        }

        false
    }
}

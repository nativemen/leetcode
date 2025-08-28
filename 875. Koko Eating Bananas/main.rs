struct Solution;

impl Solution {
    pub fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32 {
        fn can_eating(piles: &Vec<i32>, h: i32, k: i32) -> bool {
            let mut hours = 0;

            for &pile in piles {
                hours += (pile + k - 1) / k;
            }

            hours <= h
        }

        let mut left = 1;
        let mut right = piles.iter().max().cloned().unwrap();

        while left < right {
            let mid = (left + right) / 2;

            if can_eating(&piles, h, mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        right
    }
}
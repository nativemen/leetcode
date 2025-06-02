struct Solution;

impl Solution {
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
        let mut count = 0;
        let mut max_count = 0;

        for num in nums.into_iter() {
            count = if num == 1 { count + 1 } else { 0 };
            max_count = max_count.max(count);
        }

        max_count
    }
}

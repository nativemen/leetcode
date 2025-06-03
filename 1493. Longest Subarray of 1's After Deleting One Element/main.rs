struct Solution;

impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let size = nums.len();
        let mut slow = 0;
        let mut zeros = 0;
        let mut max_count = 0;

        for fast in 0..size {
            if nums[fast] == 0 {
                zeros += 1;
            }

            while zeros > 1 {
                if nums[slow] == 0 {
                    zeros -= 1;
                }
                slow += 1;
            }

            max_count = max_count.max(fast - slow + 1 - zeros);
        }

        if zeros == 0 {
            max_count -= 1;
        }

        max_count as i32
    }
}

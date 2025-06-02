struct Solution;

impl Solution {
    pub fn find_max_average(nums: Vec<i32>, k: i32) -> f64 {
        let mut sum = nums[..k as usize].iter().sum::<i32>();
        let mut max_sum = sum;

        for i in 0..nums.len() - k as usize {
            sum += nums[i + k as usize] - nums[i];
            max_sum = max_sum.max(sum);
        }

        max_sum as f64 / k as f64
    }
}

impl Solution {
    pub fn find_max_average(nums: Vec<i32>, k: i32) -> f64 {
        let mut sum = nums[..k as usize].iter().sum::<i32>();
        let mut max_sum = sum;

        for i in k as usize..nums.len() {
            sum += nums[i] - nums[i - k as usize];
            max_sum = max_sum.max(sum);
        }

        max_sum as f64 / k as f64
    }
}

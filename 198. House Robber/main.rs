struct Solution;

impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let size = nums.len();
        if size == 1 {
            return nums[0];
        }

        let mut dp = vec![0; size];
        dp[0] = nums[0];
        dp[1] = dp[0].max(nums[1]);
        for i in 2..size {
            dp[i] = dp[i - 1].max(dp[i - 2] + nums[i]);
        }

        dp[size - 1]
    }
}

impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let mut a = 0;
        let mut b = 0;

        for i in 0..nums.len() {
            if i % 2 == 0 {
                a = b.max(a + nums[i]);
            } else {
                b = a.max(b + nums[i]);
            }
        }

        a.max(b)
    }
}

struct Solution;

impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let size = nums.len();
        if size == 1 {
            return nums[0];
        }

        Self::rob_helper(nums[0..size - 1].to_vec()).max(Self::rob_helper(nums[1..].to_vec()))
    }

    fn rob_helper(nums: Vec<i32>) -> i32 {
        let mut prev1 = 0;
        let mut prev2 = 0;

        for i in 0..nums.len() {
            let cur = prev1.max(prev2 + nums[i]);
            prev2 = prev1;
            prev1 = cur;
        }

        prev1
    }
}

impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let size = nums.len();
        if size == 1 {
            return nums[0];
        }

        Self::rob_helper(nums[0..size - 1].to_vec()).max(Self::rob_helper(nums[1..].to_vec()))
    }

    fn rob_helper(nums: Vec<i32>) -> i32 {
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

impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let size = nums.len();
        if size == 1 {
            return nums[0];
        }

        Self::rob_helper(nums[0..size - 1].to_vec()).max(Self::rob_helper(nums[1..].to_vec()))
    }

    fn rob_helper(nums: Vec<i32>) -> i32 {
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
        let size = nums.len();
        if size == 1 {
            return nums[0];
        }

        Self::rob_helper(&nums, 0, size as i32 - 2).max(Self::rob_helper(nums, 1, size as i32 - 1))
    }

    fn rob_helper(nums: &Vec<i32>, left: i32, right: i32) -> i32 {
        if left > right {
            return 0;
        }

        let mut prev1 = 0;
        let mut prev2 = 0;
        for i in 0..right + 1 - left {
            let cur = prev1.max(prev2 + nums[left + i]);
            prev2 = prev1;
            prev1 = cur;
        }

        prev1
    }
}

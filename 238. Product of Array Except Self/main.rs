struct Solution;

impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let size = nums.len();
        let mut prefix = vec![1; size];
        let mut suffix = vec![1; size];

        for i in 1..size {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for i in (0..size - 1).rev() {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        let mut answer = vec![1; size];
        for i in 0..size {
            answer[i] = prefix[i] * suffix[i];
        }

        answer
    }
}

impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let size = nums.len();
        let mut prefix = vec![1; size];
        let mut suffix = vec![1; size];

        for i in 1..size {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for i in (0..size - 1).rev() {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        (0..size).map(|i| prefix[i] * suffix[i]).collect()
    }
}

impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let size = nums.len();
        let mut answer = vec![1; size];
        let mut prefix = 1;

        for i in 0..size {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        let mut suffix = 1;
        for i in (0..size).rev() {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        answer
    }
}

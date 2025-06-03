struct Solution;

impl Solution {
    pub fn pivot_index(nums: Vec<i32>) -> i32 {
        if nums.is_empty() {
            return -1;
        }

        let nums_size = nums.len();
        let mut prefix = vec![0; nums_size];
        let mut suffix = vec![0; nums_size];

        for i in 1..nums_size {
            prefix[i] = prefix[i - 1] + nums[i - 1];
            suffix[nums_size - 1 - i] = suffix[nums_size - i] + nums[nums_size - i];
        }

        for i in 0..nums_size {
            if prefix[i] == suffix[i] {
                return i as i32;
            }
        }

        -1
    }
}

impl Solution {
    pub fn pivot_index(nums: Vec<i32>) -> i32 {
        let nums_size = nums.len();
        let total = nums.iter().sum::<i32>();
        let mut left = 0;

        for i in 0..nums_size {
            let right = total - nums[i] - left;

            if left == right {
                return i as i32;
            }

            left += nums[i];
        }

        -1
    }
}

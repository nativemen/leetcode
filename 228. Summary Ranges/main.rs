struct Solution;

impl Solution {
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        let mut result = Vec::new();
        let mut i = 0;
        let size = nums.len();

        while i < size {
            let start = nums[i];

            while i + 1 < size && nums[i + 1] == nums[i] + 1 {
                i += 1;
            }

            if start == nums[i] {
                result.push(start.to_string());
            } else {
                result.push(start.to_string() + "->" + &nums[i].to_string());
            }

            i += 1;
        }

        result
    }
}

impl Solution {
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        let mut result = Vec::new();
        let mut i = 0;
        let size = nums.len();

        while i < size {
            let start = nums[i];

            while i + 1 < size && nums[i + 1] == nums[i] + 1 {
                i += 1;
            }

            if start == nums[i] {
                result.push(format!("{}", start));
            } else {
                result.push(format!("{}->{}", start, nums[i]));
            }

            i += 1;
        }

        result
    }
}

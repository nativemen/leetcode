struct Solution;

impl Solution {
    pub fn min_sub_array_len(target: i32, nums: Vec<i32>) -> i32 {
        let mut result = i32::MAX;
        let mut sum = 0;
        let mut left = 0;

        for (i, num) in nums.iter().enumerate() {
            sum += num;

            while sum >= target {
                result = result.min(i as i32 - left + 1);
                sum -= nums[left as usize];
                left += 1;
            }
        }

        if result == i32::MAX {
            0
        } else {
            result
        }
    }
}

impl Solution {
    pub fn min_sub_array_len(target: i32, nums: Vec<i32>) -> i32 {
        let mut result = i32::MAX;
        let mut sum = 0;
        let mut left = 0;

        for i in 0..nums.len() {
            sum += nums[i];

            while sum >= target {
                result = result.min(i as i32 - left + 1);
                sum -= nums[left as usize];
                left += 1;
            }
        }

        match result {
            i32::MAX => 0,
            _ => result,
        }
    }
}

struct Solution;

impl Solution {
    pub fn max_operations(nums: Vec<i32>, k: i32) -> i32 {
        let mut nums = nums;
        nums.sort_unstable();

        let mut count = 0;
        let mut left = 0;
        let mut right = nums.len() as i32 - 1;

        while right >= 0 && nums[right as usize] >= k {
            right -= 1;
        }

        while left < right {
            let target = k - nums[left as usize];

            if target == nums[right as usize] {
                count += 1;
                left += 1;
                right -= 1;
            } else if target < nums[right as usize] {
                right -= 1;
            } else {
                left += 1;
            }
        }

        count
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn max_operations(nums: Vec<i32>, k: i32) -> i32 {
        let mut freq = HashMap::new();
        let mut count = 0;

        for i in 0..nums.len() {
            if nums[i] < k {
                let target = k - nums[i];

                if !freq.contains_key(&target) || freq[&target] == 0 {
                    freq.entry(nums[i]).and_modify(|n| *n += 1).or_insert(1);
                } else {
                    count += 1;
                    freq.entry(target).and_modify(|n| *n -= 1);
                }
            }
        }

        count
    }
}

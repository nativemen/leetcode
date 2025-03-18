struct Solution;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        if nums.is_empty() {
            return 0;
        }

        let mut nums = nums;
        nums.sort();

        let mut count = 1;
        let mut max_count = 1;

        for i in 1..nums.len() {
            if nums[i] == nums[i - 1] {
                continue;
            } else if nums[i] == nums[i - 1] + 1 {
                count += 1;
            } else {
                count = 1;
            }

            max_count = max_count.max(count);
        }

        max_count
    }
}

use std::collections::HashSet;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        if nums.is_empty() {
            return 0;
        }

        let hashset: HashSet<i32> = HashSet::from_iter(nums.into_iter());

        let mut max_count = 1;

        for &num in hashset.iter() {
            if hashset.contains(&(num - 1)) {
                continue;
            }

            let mut count = 1;
            let mut last = num;

            while hashset.contains(&(last + 1)) {
                count += 1;
                last += 1;
            }

            max_count = max_count.max(count);
        }

        max_count
    }
}

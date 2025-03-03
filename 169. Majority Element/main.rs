struct Solution;

impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.sort();

        nums[nums.len() / 2]
    }
}

impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut major = 0;
        let mut count = 0;

        for num in nums {
            if count == 0 {
                major = num;
                count += 1;
            } else {
                if major == num {
                    count += 1;
                } else {
                    count -= 1;
                }
            }
        }

        major
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut maps = HashMap::new();
        let size = nums.len();

        for num in nums {
            let count = maps.entry(num).or_insert(0);
            *count += 1;
            if *count > size / 2 {
                return num;
            }
        }

        0
    }
}

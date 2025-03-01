struct Solution;

impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let size = nums.len() as i32;
        (size + 1) * size / 2 - nums.iter().sum::<i32>()
    }
}

impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let size = nums.len() as i32;

        for i in 0..size {
            if !nums.contains(&i) {
                return i;
            }
        }

        size
    }
}

impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let size = nums.len();
        let mut result = size;

        for i in 0..size {
            result ^= i ^ nums[i] as usize;
        }

        result as i32
    }
}

impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let size = nums.len() as i32;
        let mut result = size;

        for i in 0..size {
            result += i - nums[i as usize];
        }

        result
    }
}

impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.sort();
        let size = nums.len() as i32;

        for i in 0..size {
            if i != nums[i as usize] {
                return i;
            }
        }

        size
    }
}

use std::collections::HashSet;

impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let set: HashSet<i32> = nums.into_iter().collect();

        for i in 0..=set.len() as i32 {
            if !set.contains(&i) {
                return i;
            }
        }

        set.len() as i32
    }
}

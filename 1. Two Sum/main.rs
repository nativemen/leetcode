impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        for i in 0..nums.len() - 1 {
            let obj = target - nums[i];
            for j in i + 1..nums.len() {
                if (obj == nums[j]) {
                    return vec![i as i32, j as i32];
                }
            }
        }

        return vec![];
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut hashmap = HashMap::new();

        for i in 0..nums.len() {
            let obj = target - nums[i];
            if hashmap.contains_key(&obj) {
                return vec![*hashmap.get(&obj).unwrap(), i as i32];
            }

            hashmap.entry(nums[i]).or_insert(i as i32);
        }

        return vec![];
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut hashmap = HashMap::new();

        for i in 0..nums.len() {
            let obj = target - nums[i];
            if let Some(&index) = hashmap.get(&obj) {
                return vec![index, i as i32];
            }

            hashmap.entry(nums[i]).or_insert(i as i32);
        }

        return vec![];
    }
}
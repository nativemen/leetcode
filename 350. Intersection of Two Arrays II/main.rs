impl Solution {
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut nums2 = nums2.clone();
        nums1
            .iter()
            .filter(|&x| {
                if let Some(pos) = nums2.iter().position(|y| y == x) {
                    nums2.remove(pos);
                    true
                } else {
                    false
                }
            })
            .cloned()
            .collect()
    }
}

const ARRAY_SIZE: usize = 1001;

impl Solution {
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut count1 = [0; ARRAY_SIZE];
        let mut count2 = [0; ARRAY_SIZE];

        for num in nums1 {
            count1[num as usize] += 1;
        }

        for num in nums2 {
            count2[num as usize] += 1;
        }

        let mut result = Vec::new();
        for i in 0..ARRAY_SIZE {
            let count = count1[i].min(count2[i]);
            for _ in 0..count {
                result.push(i as i32);
            }
        }

        result
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut hashmap1 = HashMap::new();
        let mut result = Vec::new();

        for num in nums1 {
            *hashmap1.entry(num).or_insert(0) += 1;
        }

        for num in nums2 {
            hashmap1.entry(num).and_modify(|count| {
                if *count > 0 {
                    result.push(num);
                    *count -= 1;
                }
            });
        }

        result
    }
}

struct Solution;

use std::collections::HashMap;

impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let mut maps = HashMap::new();

        for (i, num) in nums.iter().enumerate() {
            if let Some(&index) = maps.get(num) {
                if i as i32 - index as i32 <= k {
                    return true;
                }
            }

            *maps.entry(num).or_insert(0) = i;
        }

        false
    }
}

impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let mut seen = Vec::new();

        for num in nums {
            if seen.len() > k as usize {
                seen.remove(0);
            }

            if seen.contains(&num) {
                return true;
            }

            seen.push(num);
        }

        false
    }
}

impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let mut maps = Vec::new();

        for (i, &num) in nums.iter().enumerate() {
            maps.push((num, i as i32));
        }

        maps.sort_by_key(|&(num, index)| num);

        for i in 1..maps.len() {
            if maps[i].0 == maps[i - 1].0 && maps[i].1 - maps[i - 1].1 <= k {
                return true;
            }
        }

        false
    }
}

impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        for i in 0..nums.len() {
            for j in i + 1..nums.len().min(i + k as usize + 1) {
                if nums[i] == nums[j] {
                    return true;
                }
            }
        }

        false
    }
}

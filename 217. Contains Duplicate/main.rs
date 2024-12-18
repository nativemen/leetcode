use std::collections::HashSet;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut hashset: HashSet<i32> = HashSet::new();

        for num in nums {
            if !hashset.insert(num) {
                return true;
            }
        }

        false
    }
}

use std::collections::HashSet;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut hashset: HashSet<i32> = HashSet::new();
        !nums.iter().all(|&num| hashset.insert(num))
    }
}

use std::collections::HashSet;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut hashset: HashSet<i32> = nums.iter().collect();
        hashset.len() < nums.len()
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut hashmap: HashMap<i32, i32> = HashMap::new();

        for num in nums {
            if hashmap.get(&num).is_some() {
                return true;
            }

            hashmap.entry(num).or_default();
        }

        false
    }
}

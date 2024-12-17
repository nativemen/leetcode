use std::collections::HashSet;

impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut hashset: HashSet<i32> = HashSet::new();
        let mut count = 0;

        nums.retain(|&num| {
            if hashset.insert(num) {
                count += 1;
                true
            } else {
                false
            }
        });

        count
    }
}

impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        nums.dedup();

        nums.len() as i32
    }
}

impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut j = 1;

        for i in 1..nums.len() {
            if nums[i] != nums[i - 1] {
                nums[j] = nums[i];
                j += 1;
            }
        }

        j as i32
    }
}

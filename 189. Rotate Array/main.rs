impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let count = k as usize % nums.len();
        nums.rotate_right(count);
    }
}

impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let index = nums.len() - k as usize % nums.len();
        nums.clone_from(
            &nums[index..]
                .iter()
                .chain(nums[..index].iter())
                .cloned()
                .collect(),
        );
    }
}

impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let index = nums.len() - k as usize % nums.len();
        nums.clone_from([nums[index..].cloned(), nums[..index].cloned()].concat());
    }
}

impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let index = nums.len() - k as usize % nums.len();
        nums.clone_from([nums[index..].cloned(), nums[..index].cloned()].concat());
    }
}

impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let index = nums.len() - k as usize % nums.len();
        nums[..index].reverse();
        nums[index..].reverse();
        nums.reverse();
    }
}

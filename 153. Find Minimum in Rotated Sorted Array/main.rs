struct Solution;

impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32 {
        nums.iter().min().unwrap().to_owned() as i32
    }
}

impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut right = nums.len() as i32 - 1;

        while left < right {
            let mid = (left + right) / 2;
            if nums[mid as usize] <= nums[right as usize] {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        nums[left as usize]
    }
}

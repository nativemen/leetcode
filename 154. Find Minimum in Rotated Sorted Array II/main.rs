struct Solution;

impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32 {
        *nums.iter().min().unwrap_or(&0)
    }
}

impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32 {
        *nums.iter().min().unwrap()
    }
}

impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut right = nums.len() as i32 - 1;

        while left < right {
            let mid = left + (right - left) / 2;

            if nums[mid as usize] < nums[right as usize] {
                right = mid;
            } else if nums[mid as usize] > nums[right as usize] {
                left = mid + 1;
            } else {
                right -= 1;
            }
        }

        nums[right as usize]
    }
}

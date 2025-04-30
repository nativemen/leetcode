struct Solution;

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        if let Some(index) = nums.iter().position(|&x| x == target) {
            index as i32
        } else {
            -1
        }
    }
}

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut left = 0;
        let mut right = nums.len() - 1;

        while left <= right {
            let mid = (left + right) / 2;

            if target == nums[mid] {
                return mid as i32;
            }

            if nums[left] <= nums[mid] {
                if nums[left] <= target && target < nums[mid] {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if nums[mid] < target && target <= nums[right] {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        -1
    }
}

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut min_val = i32::MAX;
        let mut index = 0;
        let size = nums.len();

        for i in 0..size {
            if min_val > nums[i] {
                min_val = nums[i];
                index = i;
            }
        }

        let mut left = index as i32;
        let mut right = left + size as i32 - 1;

        while left <= right {
            let mid = (left + right) / 2;

            if target == nums[mid as usize % size] {
                return mid % size as i32;
            } else if target < nums[mid as usize % size] {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        -1
    }
}

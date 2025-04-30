struct Solution;

impl Solution {
    pub fn find_peak_element(nums: Vec<i32>) -> i32 {
        let size = nums.len();

        if size <= 0 {
            return -1;
        }

        if size == 1 {
            return 0;
        }

        for i in 0..size - 1 {
            if nums[i] > nums[i + 1] {
                return i as i32;
            }
        }

        size as i32 - 1
    }
}

impl Solution {
    pub fn find_peak_element(nums: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut right = nums.len() - 1;

        while left < right {
            let mid = (left + right) / 2;

            if nums[mid] > nums[mid + 1] {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        left as i32
    }
}

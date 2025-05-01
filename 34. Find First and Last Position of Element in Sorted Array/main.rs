struct Solution;

impl Solution {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut result = vec![-1, -1];
        let size = nums.len() as i32;
        let mut left = 0;
        let mut right = size - 1;

        while left <= right {
            let mid = (left + right) / 2;

            if target <= nums[mid as usize] {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if left >= size || nums[left as usize] != target {
            return result;
        }

        result[0] = left;
        right = size - 1;

        while left <= right {
            let mid = (left + right) / 2;

            if target < nums[mid as usize] {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        result[1] = right;

        result
    }
}

impl Solution {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut result = vec![-1, -1];
        let size = nums.len();

        for i in 0..size {
            if target == nums[i] {
                result[0] = i as i32;
                break;
            }
        }

        for i in (0..size).rev() {
            if target == nums[i] {
                result[1] = i as i32;
                break;
            }
        }

        return result;
    }
}

impl Solution {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        if nums.contains(&target) {
            vec![
                nums.partition_point(|&x| x < target) as i32,
                nums.partition_point(|&x| x <= target) as i32 - 1,
            ]
        } else {
            vec![-1, -1]
        }
    }
}

struct Solution;

impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let nums_size = nums.len();

        for i in 0..nums_size {
            if nums[i] >= target {
                return i as i32;
            }
        }

        nums_size as i32
    }
}

impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let mut nums = nums;

        nums.push(target);
        nums.sort();
        nums.iter().position(|num| target.eq(num)).unwrap() as i32
    }
}

impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let mut left = 0;
        let mut right = nums.len() as i32 - 1;

        while left <= right {
            let mid = (left + right) / 2;

            if nums[mid as usize] == target {
                return mid;
            } else if nums[mid as usize] < target {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
}

impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let nums_size = nums.len();

        if nums_size == 0 {
            return 0;
        }

        let mid = nums_size / 2;

        if nums[mid] == target {
            return mid as i32;
        } else if nums[mid] < target {
            return mid as i32 + 1 + Self::search_insert(nums[mid + 1..].to_vec(), target);
        } else {
            return Self::search_insert(nums[..mid].to_vec(), target);
        }
    }
}

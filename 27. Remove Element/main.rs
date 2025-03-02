impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut left = 0;
        let mut right = nums.len() as i32 - 1;

        while left <= right {
            if nums[left as usize] != val {
                left += 1;
                continue;
            }

            if nums[right as usize] == val {
                right -= 1;
                continue;
            }

            nums[left as usize] = nums[right as usize];
            nums[right as usize] = val;
        }

        left
    }
}

impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut remain = Vec::new();

        for num in nums.into_iter() {
            if *num != val {
                remain.push(*num);
            }
        }

        nums.clear();
        nums.extend(remain.into_iter());

        nums.len() as i32
    }
}

impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut count = 0;

        for i in 0..nums.len() {
            if nums[i] != val {
                nums.swap(count, i);
                count += 1;
            }
        }

        count as i32
    }
}

impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        loop {
            match nums.iter().position(|&num| num == val) {
                Some(index) => {
                    nums.remove(index);
                }
                None => break,
            }
        }

        nums.len() as i32
    }
}

impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut i = 0;

        while i < nums.len() {
            if nums[i] == val {
                nums.swap_remove(i);
            } else {
                i += 1;
            }
        }

        nums.len() as i32
    }
}

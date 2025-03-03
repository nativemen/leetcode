struct Solution;

impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let size = nums.len();
        let mut can_reach = vec![false; size];

        can_reach[0] = true;
        for i in 0..size {
            if !can_reach[i] {
                return false;
            }

            for j in i..size.min(nums[i] as usize + i + 1) {
                can_reach[j] = true;
            }
        }

        true
    }
}

impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let size = nums.len();
        let mut max_reach = 0;

        for i in 0..size {
            if i > max_reach {
                return false;
            }

            max_reach = max_reach.max(i + nums[i] as usize);
        }

        true
    }
}

impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let size = nums.len();
        let mut target = size as i32 - 1;
        let mut start = size as i32 - 2;

        while start >= 0 {
            if start + nums[start as usize] >= target {
                target = start;
            }
            start -= 1;
        }

        target == 0
    }
}

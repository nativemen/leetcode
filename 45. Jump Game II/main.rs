struct Solution;

impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let size = nums.len();
        let mut jumps = vec![i32::MAX; size];

        jumps[0] = 0;
        for i in 0..size {
            for j in i + 1..size.min(nums[i] as usize + i + 1) {
                jumps[j] = jumps[j].min(jumps[i] + 1);
            }
        }

        jumps[size - 1]
    }
}

impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let size = nums.len();
        let mut left = 0;
        let mut right = 0;
        let mut jumps = 0;

        while right < size - 1 {
            let mut far_reach = 0;
            for i in left..=right {
                far_reach = far_reach.max(nums[i] as usize + i);
            }

            left = right + 1;
            right = far_reach;
            jumps += 1;
        }

        return jumps;
    }
}

impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let size = nums.len();
        if size <= 1 {
            return 0;
        }

        let mut cur_farthest = 0;
        let mut next_farthest = 0;
        let mut jumps = 0;

        for i in 0..size {
            next_farthest = next_farthest.max(nums[i] as usize + i);
            if i == cur_farthest {
                jumps += 1;
                cur_farthest = next_farthest;
                if cur_farthest >= size - 1 {
                    break;
                }
            }
        }

        jumps
    }
}

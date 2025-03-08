struct Solution;

impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let size = height.len();
        let mut left = 0;
        let mut right = size as i32 - 1;
        let mut left_max = 0;
        let mut right_max = 0;
        let mut total = 0;

        while left <= right {
            if height[left as usize] <= height[right as usize] {
                if height[left as usize] <= left_max {
                    total += left_max - height[left as usize];
                } else {
                    left_max = height[left as usize];
                }
                left += 1;
            } else {
                if height[right as usize] <= right_max {
                    total += right_max - height[right as usize];
                } else {
                    right_max = height[right as usize];
                }
                right -= 1;
            }
        }

        total
    }
}

impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let size = height.len();
        let mut prefix_max = vec![0; size];

        for i in 1..size {
            prefix_max[i] = prefix_max[i - 1].max(height[i - 1]);
        }

        let mut suffix_max = vec![0; size];

        for i in (0..size - 1).rev() {
            suffix_max[i] = suffix_max[i + 1].max(height[i + 1]);
        }

        let mut total = 0;

        for i in 0..size {
            let top = prefix_max[i].min(suffix_max[i]);
            if top >= height[i] {
                total += top - height[i];
            }
        }

        total
    }
}

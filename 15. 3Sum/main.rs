struct Solution;

impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        let size = nums.len();
        let mut nums = nums;
        nums.sort();

        for cur in 0..size - 2 {
            if cur > 0 && nums[cur] == nums[cur - 1] {
                continue;
            }

            let mut left = cur + 1;
            let mut right = size - 1;

            while left < right {
                let sum = nums[cur] + nums[left] + nums[right];
                if sum < 0 {
                    left += 1;
                } else if sum > 0 {
                    right -= 1;
                } else {
                    result.push(vec![nums[cur], nums[left], nums[right]]);
                    while left < right && nums[left] == nums[left + 1] {
                        left += 1;
                    }
                    left += 1;
                    while left < right && nums[right] == nums[right - 1] {
                        right -= 1;
                    }
                    right -= 1;
                }
            }
        }

        result
    }
}

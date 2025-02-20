struct Solution;

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut max_sum = i32::MIN;
        let mut sum = 0;

        for num in nums {
            sum = num.max(sum + num);
            max_sum = max_sum.max(sum);
        }

        max_sum
    }
}


impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut max_sum = nums[0];
        let mut sum = nums[0];

        for i in 1..nums.len() {
            if sum < 0 {
                sum = nums[i];
            } else {
                sum += nums[i];
            }

            if max_sum < sum {
                max_sum = sum;
            }
        }

        max_sum
    }
}
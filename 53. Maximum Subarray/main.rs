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

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut max_sum = nums[0];
        let mut sum = nums[0];

        for &num in &nums[1..] {
            sum = num.max(sum + num);
            max_sum = max_sum.max(sum);
        }

        max_sum
    }
}

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        Self::max_sub_array_helper(&nums, 0, nums.len() - 1)
    }

    fn max_sub_array_helper(nums: &Vec<i32>, left: usize, right: usize) -> i32 {
        if left == right {
            return nums[left];
        }

        let mid = (left + right) / 2;
        let left_max = Self::max_sub_array_helper(nums, left, mid);
        let right_max = Self::max_sub_array_helper(nums, mid + 1, right);
        let crossing_max = Self::max_crossing_sub_array(nums, left, mid, right);

        left_max.max(right_max).max(crossing_max)
    }

    fn max_crossing_sub_array(nums: &Vec<i32>, left: usize, mid: usize, right: usize) -> i32 {
        let mut left_sum = i32::MIN;
        let mut sum = 0;

        for i in (left..=mid).rev() {
            sum += nums[i];
            if (sum > left_sum) {
                left_sum = sum;
            }
        }

        let mut right_sum = i32::MIN;
        sum = 0;

        for i in mid + 1..=right {
            sum += nums[i];
            if (sum > right_sum) {
                right_sum = sum;
            }
        }

        return left_sum + right_sum;
    }
}

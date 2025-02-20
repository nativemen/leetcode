struct Solution;

impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let mut max_prod = i32::MIN;
        let mut left_prod = 1;
        let mut right_prod = 1;
        let size = nums.len();

        for i in 0..size {
            left_prod *= nums[i];
            right_prod *= nums[size - 1 - i];
            max_prod = max_prod.max(left_prod);
            max_prod = max_prod.max(right_prod);
            if left_prod == 0 {
                left_prod = 1;
            }
            if right_prod == 0 {
                right_prod = 1;
            }
        }

        max_prod
    }
}

impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let mut max_prod = i32::MIN;
        let mut cur_min = 1;
        let mut cur_max = 1;

        for num in nums {
            let temp = cur_max * num;
            cur_max = temp.max(cur_min * num).max(num);
            cur_min = temp.min(cur_min * num).min(num);
            max_prod = max_prod.max(cur_max);
        }

        max_prod
    }
}

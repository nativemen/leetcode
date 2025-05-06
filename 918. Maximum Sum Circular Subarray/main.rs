struct Solution;

impl Solution {
    pub fn max_subarray_sum_circular(nums: Vec<i32>) -> i32 {
        let mut max_sum = i32::MIN;
        let mut min_sum = i32::MAX;
        let mut cur_max = 0;
        let mut cur_min = 0;
        let mut total_sum = 0;

        for num in nums {
            cur_max = num.max(cur_max + num);
            max_sum = max_sum.max(cur_max);
            cur_min = num.min(cur_min + num);
            min_sum = min_sum.min(cur_min);
            total_sum += num;
        }

        if max_sum < 0 {
            return max_sum;
        }

        max_sum.max(total_sum - min_sum)
    }
}

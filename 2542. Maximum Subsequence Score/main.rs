struct Solution;

use std::collections::BinaryHeap;

impl Solution {
    pub fn max_score(nums1: Vec<i32>, nums2: Vec<i32>, k: i32) -> i64 {
        let mut nums = nums1.into_iter().zip(nums2.into_iter()).collect::<Vec<_>>();
        let mut heap = BinaryHeap::new();
        let mut result = 0;
        let mut sum = 0;

        nums.sort_by_key(|(_, y)| -(*y));

        for i in 0..nums.len() {
            heap.push(-nums[i].0);
            sum += nums[i].0 as i64;

            if heap.len() > k as usize {
                sum -= -heap.pop().unwrap() as i64;
            }

            if heap.len() == k as usize {
                result = result.max(sum * nums[i].1 as i64)
            }
        }

        result
    }
}

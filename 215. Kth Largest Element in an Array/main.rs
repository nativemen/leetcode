struct Solution;

impl Solution {
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        let mut nums = nums;

        nums.sort();

        nums[nums.len() - k as usize]
    }
}

impl Solution {
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        const ARRAY_SIZE: usize = 20001;
        const INDEX_OFFSET: usize = 10000;
        let mut count = vec![0; ARRAY_SIZE];
        let mut k = k;

        for &num in nums.iter() {
            count[num as usize + INDEX_OFFSET] += 1;
        }

        for i in (0..ARRAY_SIZE).rev() {
            if k <= count[i] {
                return i as i32 - INDEX_OFFSET as i32;
            }

            k -= count[i];
        }

        0 - INDEX_OFFSET as i32
    }
}

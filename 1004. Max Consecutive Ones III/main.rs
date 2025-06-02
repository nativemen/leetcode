struct Solution;

impl Solution {
    pub fn longest_ones(nums: Vec<i32>, k: i32) -> i32 {
        let len = nums.len();
        let mut max_count = 0;
        let mut zeros = 0;
        let mut slow = 0;
        let mut fast = 0;

        while fast < len {
            if nums[fast] == 0 {
                if zeros == k {
                    max_count = max_count.max(fast - slow);
                }

                while zeros == k {
                    if nums[slow] == 0 {
                        zeros -= 1;
                    }
                    slow += 1;
                }

                zeros += 1;
            }

            fast += 1;
        }

        max_count.max(fast - slow) as i32
    }
}

impl Solution {
    pub fn longest_ones(nums: Vec<i32>, k: i32) -> i32 {}
}

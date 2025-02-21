struct Solution;

impl Solution {
    pub fn shuffle(nums: Vec<i32>, n: i32) -> Vec<i32> {
        let mut res = Vec::new();

        for i in 0..n as usize {
            res.push(nums[i]);
            res.push(nums[i + n as usize]);
        }

        res
    }
}

impl Solution {
    pub fn shuffle(nums: Vec<i32>, n: i32) -> Vec<i32> {
        (0..2 * n as usize)
            .map(|i| {
                if i % 2 == 0 {
                    nums[i / 2]
                } else {
                    nums[i / 2 + n as usize]
                }
            })
            .collect()
    }
}
struct Solution;

impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let nums_size = nums.len();

        if nums_size == 0 {
            return 0;
        }

        let mut seq = Vec::new();
        seq.push(nums[0]);

        for i in 1..nums_size {
            if seq[seq.len() - 1] < nums[i] {
                seq.push(nums[i]);
            } else {
                if let Err(index) = seq.binary_search(&nums[i]) {
                    seq[index] = nums[i];
                }
            }
        }

        seq.len() as i32
    }
}

impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let nums_size = nums.len();

        if nums_size == 0 {
            return 0;
        }

        let mut dp = vec![1; nums_size + 1];

        for i in 0..nums_size {
            for j in 0..i {
                if nums[i] > nums[j] {
                    dp[i] = dp[i].max(dp[j] + 1)
                }
            }
        }

        *dp.iter().max().unwrap()
    }
}

impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let nums_size = nums.len();

        if nums_size == 0 {
            return 0;
        }

        let mut dp = vec![1; nums_size + 1];

        for i in (0..nums_size).rev() {
            for j in i..nums_size {
                if nums[i] < nums[j] {
                    dp[i] = dp[i].max(dp[j] + 1)
                }
            }
        }

        *dp.iter().max().unwrap()
    }
}

impl Solution {
    fn binary_search(seq: &Vec<i32>, target: i32) -> usize {
        let mut left = 0;
        let mut right = seq.len() as i32 - 1;

        while left <= right {
            let mid = (left + right) / 2;

            if seq[mid as usize] < target {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        left as usize
    }

    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let nums_size = nums.len();

        if nums_size == 0 {
            return 0;
        }

        let mut seq = Vec::new();
        seq.push(nums[0]);

        for i in 1..nums_size {
            if seq[seq.len() - 1] < nums[i] {
                seq.push(nums[i]);
            } else {
                let index = Self::binary_search(&seq, nums[i]);
                seq[index] = nums[i];
            }
        }

        seq.len() as i32
    }
}

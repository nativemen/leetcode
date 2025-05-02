struct Solution;

impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        if m <= 0 || n <= 0 {
            return 0;
        }

        if m == 1 || n == 1 {
            return 1;
        }

        let mut dp = vec![vec![1; n as usize]; m as usize];

        for i in 1..m as usize {
            for j in 1..n as usize {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        dp[m as usize - 1][n as usize - 1]
    }
}

impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        if m <= 0 || n <= 0 {
            return 0;
        }

        if m == 1 || n == 1 {
            return 1;
        }

        let mut dp = vec![1; n as usize];

        for _ in 1..m as usize {
            for j in 1..n as usize {
                dp[j] += dp[j - 1];
            }
        }

        dp[n as usize - 1]
    }
}
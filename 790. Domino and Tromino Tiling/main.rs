struct Solution;

impl Solution {
    pub fn num_tilings(n: i32) -> i32 {
        let modulus = 10i64.pow(9) + 7;

        if n <= 2 {
            return n;
        }

        if n == 3 {
            return 5;
        }

        let mut dp = vec![0; n as usize];
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 5;

        for i in 3..n as usize {
            dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % modulus;
        }

        dp[n as usize - 1] as i32
    }
}

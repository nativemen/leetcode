struct Solution;

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n <= 1 {
            return 1;
        }

        let mut a = 1;
        let mut b = 1;

        for i in 2..=n {
            let temp = b;
            b = a + b;
            a = temp;
        }

        b
    }
}

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n <= 1 {
            return 1;
        }

        const VECTOR_SIZE: usize = 46;
        let mut dp = vec![0; VECTOR_SIZE];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for i in 3..=n as usize {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        dp[n as usize]
    }
}

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        (0..n - 1)
            .fold((1, 1), |(res, prev), _| (res + prev, res))
            .0
    }
}

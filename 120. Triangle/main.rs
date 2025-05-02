struct Solution;

impl Solution {
    pub fn minimum_total(triangle: Vec<Vec<i32>>) -> i32 {
        let row_size = triangle.len();

        if row_size <= 0 {
            return 0;
        }

        let mut triangle = triangle;

        for i in (0..row_size - 1).rev() {
            for j in 0..triangle[i].len() {
                triangle[i][j] += triangle[i + 1][j].min(triangle[i + 1][j + 1])
            }
        }

        triangle[0][0]
    }
}

impl Solution {
    pub fn minimum_total(triangle: Vec<Vec<i32>>) -> i32 {
        let row_size = triangle.len();

        if row_size <= 0 {
            return 0;
        }

        let mut dp = Vec::new();
        dp.push(vec![triangle[0][0]]);

        for i in 1..row_size {
            dp.push(vec![0; triangle[i].len()]);
            for j in 0..triangle[i].len() {
                if j == 0 {
                    dp[i][0] = dp[i - 1][0] + triangle[i][0];
                } else if j == triangle[i].len() - 1 {
                    dp[i][triangle[i].len() - 1] =
                        dp[i - 1][triangle[i - 1].len() - 1] + triangle[i][triangle[i].len() - 1];
                } else {
                    dp[i][j] = dp[i - 1][j].min(dp[i - 1][j - 1]) + triangle[i][j];
                }
            }
        }

        dp[row_size - 1].iter().min().unwrap().to_owned()
    }
}

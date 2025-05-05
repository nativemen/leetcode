struct Solution;

impl Solution {
    pub fn maximal_square(matrix: Vec<Vec<char>>) -> i32 {
        if matrix.is_empty() {
            return 0;
        }

        let row_size = matrix.len();
        let col_size = matrix[0].len();
        let mut dp = vec![vec![0; col_size]; row_size];
        let mut max_size = 0;

        for i in 0..row_size {
            for j in 0..col_size {
                if matrix[i][j] == '1' {
                    if i == 0 || j == 0 {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 1 + dp[i - 1][j].min(dp[i][j - 1].min(dp[i - 1][j - 1]));
                    }

                    max_size = max_size.max(dp[i][j]);
                }
            }
        }

        max_size * max_size
    }
}

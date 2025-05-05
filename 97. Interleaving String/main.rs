struct Solution;

impl Solution {
    fn check_interleave(
        v1: &[u8],
        v2: &[u8],
        v3: &[u8],
        i: usize,
        j: usize,
        k: usize,
        dp: &mut Vec<Vec<i32>>,
    ) -> bool {
        let len1 = v1.len();
        let len2 = v2.len();
        let len3 = v3.len();

        if i == len1 && j == len2 && k == len3 {
            return true;
        }

        if k == len3 {
            return false;
        }

        if dp[i][j] != -1 {
            return dp[i][j] == 1;
        }

        let mut cond1 = false;
        let mut cond2 = false;

        if i < len1 && k < len3 && v1[i] == v3[k] {
            cond1 = Self::check_interleave(v1, v2, v3, i + 1, j, k + 1, dp);
            dp[i][j] = cond1 as i32;
        }

        if j < len2 && k < len3 && v2[j] == v3[k] {
            cond2 = Self::check_interleave(v1, v2, v3, i, j + 1, k + 1, dp);
            dp[i][j] = cond2 as i32;
        }

        cond1 || cond2
    }

    pub fn is_interleave(s1: String, s2: String, s3: String) -> bool {
        let v1 = s1.as_bytes();
        let v2 = s2.as_bytes();
        let v3 = s3.as_bytes();

        if v1.len() + v2.len() != v3.len() {
            return false;
        }

        let mut dp = vec![vec![-1; v2.len() + 1]; v1.len() + 1];

        Self::check_interleave(v1, v2, v3, 0, 0, 0, &mut dp)
    }
}

impl Solution {
    pub fn is_interleave(s1: String, s2: String, s3: String) -> bool {
        let v1 = s1.as_bytes();
        let v2 = s2.as_bytes();
        let v3 = s3.as_bytes();

        if v1.len() + v2.len() != v3.len() {
            return false;
        }

        let mut dp = vec![vec![false; v2.len() + 1]; v1.len() + 1];
        dp[0][0] = true;

        for i in 0..v1.len() + 1 {
            for j in 0..v2.len() + 1 {
                if i == 0 && j > 0 {
                    dp[0][j] = dp[0][j - 1] && v2[j - 1] == v3[j - 1];
                } else if j == 0 && i > 0 {
                    dp[i][0] = dp[i - 1][0] && v1[i - 1] == v3[i - 1];
                } else if i > 0 && j > 0 {
                    dp[i][j] = (dp[i - 1][j] && v1[i - 1] == v3[i + j - 1])
                        || (dp[i][j - 1] && v2[j - 1] == v3[i + j - 1]);
                }
            }
        }

        dp[v1.len()][v2.len()]
    }
}

impl Solution {
    pub fn is_interleave(s1: String, s2: String, s3: String) -> bool {
        let v1 = s1.as_bytes();
        let v2 = s2.as_bytes();
        let v3 = s3.as_bytes();

        if v1.len() + v2.len() != v3.len() {
            return false;
        }

        let mut dp = vec![vec![false; v2.len() + 1]; v1.len() + 1];
        dp[0][0] = true;

        for i in 0..v1.len() + 1 {
            for j in 0..v2.len() + 1 {
                if i > 0 && v1[i - 1] == v3[i + j - 1] {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }

                if j > 0 && v2[j - 1] == v3[i + j - 1] {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }

        dp[v1.len()][v2.len()]
    }
}

impl Solution {
    pub fn is_interleave(s1: String, s2: String, s3: String) -> bool {
        let v1 = s1.as_bytes();
        let v2 = s2.as_bytes();
        let v3 = s3.as_bytes();

        if v1.len() + v2.len() != v3.len() {
            return false;
        }

        let mut dp = vec![false; v2.len() + 1];
        dp[0] = true;

        for i in 0..v1.len() + 1 {
            for j in 0..v2.len() + 1 {
                if i == 0 && j > 0 {
                    dp[j] = dp[j - 1] && v2[j - 1] == v3[j - 1];
                } else if j == 0 && i > 0 {
                    dp[0] = dp[0] && v1[i - 1] == v3[i - 1];
                } else if i > 0 && j > 0 {
                    dp[j] = (dp[j] && v1[i - 1] == v3[i + j - 1])
                        || (dp[j - 1] && v2[j - 1] == v3[i + j - 1]);
                }
            }
        }

        dp[v2.len()]
    }
}

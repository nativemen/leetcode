struct Solution;

impl Solution {
    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        let vec1 = text1.chars().collect::<Vec<_>>();
        let vec2 = text2.chars().collect::<Vec<_>>();
        let len1 = vec1.len();
        let len2 = vec2.len();
        let mut dp = vec![vec![0; len2]; len1];

        for i in 0..len1 {
            for j in 0..len2 {
                if vec1[i] == vec2[j] {
                    dp[i][j] = if i == 0 || j == 0 {
                        1
                    } else {
                        dp[i - 1][j - 1] + 1
                    };
                } else {
                    let first = if i == 0 { 0 } else { dp[i - 1][j] };
                    let second = if j == 0 { 0 } else { dp[i][j - 1] };
                    dp[i][j] = first.max(second);
                }
            }
        }

        dp[len1 - 1][len2 - 1]
    }
}

impl Solution {
    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        let text1 = text1.as_bytes();
        let text2 = text2.as_bytes();
        let len1 = text1.len();
        let len2 = text2.len();
        let mut dp = vec![vec![0; len2]; len1];

        for i in 0..len1 {
            for j in 0..len2 {
                if text1[i] == text2[j] {
                    dp[i][j] = if i == 0 || j == 0 {
                        1
                    } else {
                        dp[i - 1][j - 1] + 1
                    };
                } else {
                    let first = if i == 0 { 0 } else { dp[i - 1][j] };
                    let second = if j == 0 { 0 } else { dp[i][j - 1] };
                    dp[i][j] = first.max(second);
                }
            }
        }

        dp[len1 - 1][len2 - 1]
    }
}

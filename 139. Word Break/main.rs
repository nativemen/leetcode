struct Solution;

impl Solution {
    pub fn word_break(s: String, word_dict: Vec<String>) -> bool {
        let s_len = s.len();
        let word_dict_size = word_dict.len();
        let mut dp = vec![false; s_len + 1];
        dp[0] = true;

        for i in 0..s_len {
            if !dp[i] {
                continue;
            }

            for j in 0..word_dict_size {
                let word_len = word_dict[j].len();

                if i + word_len <= s_len && s[i..i + word_len].eq(&word_dict[j]) {
                    dp[i + word_len] = true;
                }
            }
        }

        dp[s_len]
    }
}

struct Solution;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let s_len = s.len();
        let mut start = 0;
        let mut max_len = 0;

        for i in 0..s_len as i32 {
            for j in 0..2 {
                let mut left = i;
                let mut right = i + j;

                while left >= 0
                    && right < s_len as i32
                    && s[left as usize..left as usize + 1] == s[right as usize..right as usize + 1]
                {
                    left -= 1;
                    right += 1;
                }

                let cur_len = right - left - 1;
                if cur_len as usize > max_len {
                    max_len = cur_len as usize;
                    start = left as usize + 1;
                }
            }
        }

        s[start..start + max_len].to_string()
    }
}

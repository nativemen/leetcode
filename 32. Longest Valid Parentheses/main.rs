struct Solution;

impl Solution {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        let mut result = 0;
        let mut left = 0;
        let mut right = 0;

        for c in s.chars() {
            if c == '(' {
                left += 1;
            } else {
                right += 1;
            }

            if left == right {
                result = result.max(left + right);
            } else if left < right {
                left = 0;
                right = 0;
            }
        }

        left = 0;
        right = 0;

        for c in s.chars().rev() {
            if c == '(' {
                left += 1;
            } else {
                right += 1;
            }

            if left == right {
                result = result.max(left + right);
            } else if left > right {
                left = 0;
                right = 0;
            }
        }

        result
    }
}

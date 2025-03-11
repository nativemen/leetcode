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

impl Solution {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        let size = s.len();
        if size == 0 {
            return 0;
        }

        let mut result = 0;
        let mut stack = Vec::new();
        stack.push(-1);

        for i in 0..size {
            if s.chars().nth(i).unwrap() == '(' {
                stack.push(i as i32);
            } else {
                stack.pop();
                if stack.is_empty() {
                    stack.push(i as i32);
                } else {
                    result = result.max(i as i32 - stack.last().unwrap());
                }
            }
        }

        result
    }
}

impl Solution {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        let size = s.len();
        if size == 0 {
            return 0;
        }

        let mut result = 0;
        let mut stack = Vec::new();
        stack.push(-1);

        for (i, c) in s.chars().enumerate() {
            if c == '(' {
                stack.push(i as i32);
            } else {
                stack.pop();
                if let Some(&n) = stack.last() {
                    result = result.max(i as i32 - n);
                } else {
                    stack.push(i as i32);
                }
            }
        }

        result
    }
}
